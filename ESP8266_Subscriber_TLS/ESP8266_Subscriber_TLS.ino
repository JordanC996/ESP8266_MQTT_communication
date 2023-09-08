
/*
 Una volta che publisher o subscriber si connettono al broker MQTT tramite la porta 8883 si stabilisce una connessione TLS tra di loro, l'obiettivo in questo programma è:
       - impostare una variabile di tempo con l'orologio dell'ora locale attraverso il protocollo ntp, in questo modo durante la connessione SSL il publisher/subscirber
         sarà in grado di stabilire se il certificato presentato dal broker è ancora valido o è scaduto  
       - settare la scheda del publisher/subscriber con il proprio certificato (da poter presentare in caso di mutua autenticazione) e con il certificato della trusted authority 
         che si dovà considerare fidata, in modo tale che qualsiasi certificato presentato dal broker firmato da questa CA sarà durante l'HS protocol
 */
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "Subscriber_secrets.h"


const int led1Pin = 0;
const int led2Pin = 2;
int flag=0;

WiFiClientSecure espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

// Questa funzione serve per sincronizzare il tempo con il protocollo ntp al fine di poter stabilire se i certificati forniti dal server al momento dell'HS protocol sono ancora validi
void setClock()
{
  //Questa funzione permette di ottenere il timezone del proprio paese, in questo caso la timezone è quella dell'europa centrale che coincide con 1*3600, la base dei tempi nel protocollo ntp è il secondo
  configTime(1*3600, 0, "it.pool.ntp.org", "time.google.com");
  // questo ciclo ha l'obiettivo di attendere la sincronizzazione dell'orologio dell'ESP8266 con quello del protocollo ntp
  Serial.print("Waiting for NTP time sync: ");
  time_t now = time(nullptr);
  while (now <  100 ) {
    delay(500); 
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("");
  struct tm timeinfo; // questa strttura permette di rappresenttare il tempo in giorni mesi e anni
  gmtime_r(&now, &timeinfo);
  timeinfo.tm_hour = timeinfo.tm_hour +2; // essendo che in qualsiasi modo io setti loffset UTC, che sia quello dell'africa meridionale o dell'europa centrale , l'orario rimane di 2 ore dietro a quello italiano, in questo modo lo aggiusto
  Serial.print("Current time: ");
  Serial.print(asctime(&timeinfo));
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA); //imposta l'ESP8266 come una Stazione e non come Access Point
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { //ciclo che attende che lo stato dell'oggetto WiFi diventi WL_CONNECTED che significa che l'ESP8266 è connesso alla rete wifi
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());  /*inizializza il generatore di numeri pseudo randomici, questa funzione ha lo scopo di rendere diverse le sequenze di numeri randomici generate
                           dalla funzione random() questa funzione prende in ingresso un seme con il quale inizializzare il generatore, nel nostro caso il seme
                           lo restituisce micros(), funzione che restituisce il numero di microsecondi a partire dai quali lo sketch è in esecuzione sulla scheda */
                        
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//funzione che viene chiamata ogni volta che viene pubblicato un messaggio sul topic al quale il client è iscritto (subscriber), serve a gestire la ricezione del messaggio, da togliere al publisher questa funzione
void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  String msg;
  for(int i=0;i<length;i++){
    msg += (char)payload[i];
    
  }
 
  if(msg == "on"){
    flag = 1;
    Serial.println("on");
  }else if(msg == "off"){
    flag = 0;
  }

}
// funzione che permette di connettersi al broker MQTT
void reconnect() {
  char err_buf[256];

  // Continua finchè il client non è connesso al broker
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Crea un random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Tentativo di connessione co n il broker settato il precedenza
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("/alarm");
    } else {
      Serial.print("failed, rc=");
      Serial.println(client.state());
      espClient.getLastSSLError(err_buf, sizeof(err_buf));
      Serial.print("SSL error: ");
      Serial.println(err_buf);
      Serial.println(" try again in 5 seconds");
      // Aspetta 5 secondi prima di riprovare
      delay(5000);
    }
  }
}

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.begin(115200);
  //serverTrustedCa è un puntatore ad un oggetto dinamico X509List che può contenere una lista (catena) di certificati che permette di ricondurre a una trusted authority, viene inizializzato dal costruttore col certificato della CA
  X509List *serverTrustedCA = new X509List(ca_cert); 
  X509List *publisherCertList = new X509List(client_cert);
  PrivateKey *publisherPrivKey = new PrivateKey(client_private_key);
  espClient.setTrustAnchors(serverTrustedCA); //funzione che prende in ingresso un certificato di una CA per considerarla come Ca fidata, in questo modo ogni certificato che arriva firmato da questa CA sarà accettato
  espClient.setClientRSACert(publisherCertList, publisherPrivKey); //funzione che prepara il certificato del publisher preso in ingresso insieme alla sua priv_key per essere inviato durante una connessione TLS (HS protocol) nel caso in cui il server lo richiedesse
  setup_wifi();
  setClock(); // Necessaria per la validazione dei certificati X509
  client.setServer(mqtt_server, 8883); //setta i dettagli del server a cui bisogna collegarsi successivamente
  client.setCallback(callback); //setta a quale funzione di callback il subbscriber dovrà riferirsi quando arriva un messaggio
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (flag == 1){
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, LOW);
  delay(200);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led1Pin, LOW);
  delay(200);
  }else{
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }
}
