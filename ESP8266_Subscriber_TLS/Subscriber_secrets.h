
const char client_private_key[] PROGMEM = R"EOF(
-----BEGIN PRIVATE KEY-----
MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDrPDxM+fL7EPw+
W8ph2qcJ4R8uT9p/gblKUhGuCZMlodpyQsYUdyz4ZjiajNOrYvJEK4UHdTDLk2z9
L1IidKmoN6kilm5HpVpdBrTge8AKIrCmFe85qEmsXx/H+KuI8wIkNRFWvsmAcspO
Xr5RI7g4L5jYMtKzfO6ljRKBd1Weu9jPmMhemXewqx5I2Y1oUgtmtNjTtqUKDCAy
pApgf8rRFuMrr1fq+UUBDtGBplFvTc/EzN24JWnoSbU0VTJVc5/N+n99Sl0qGVD9
UhMlJ08cz776MR3HpRQtF3YTSgpoGhTt4tC1l6hIoGtDm5NYCk0aJiEU2fD1LXCY
LmLH17FDAgMBAAECggEABtr1COtAPQSnZtI6L8FCNlcxfbu4nhgNap1bEL7ZSaX4
KnWutYCTNqDH/1A7Ib00jgihclbkd3JSIUv3pIBqd1GgvYMzyIu7+lNyzv312g9d
WLtX6U6+guYsx24ESO2IDCUUK2DlzDcylR3muJE5a6dbcj8c69UoVHor5jD9NXut
Cz4BojVCdX8jJiS7iCxy9JmVKJyhuKj0PHNRj8ustkh0haLCoBOfqV2lwh8iNVX/
ERSVE+mtG7nuQcYRvs+zx4mzkUt5oXar/MIr05ne9d2ce4HjX41ypuW6YR+qPcsb
sQ4rItPdfelrdSs5THNbjxmkSZ5FZajcwL12JvrAZQKBgQDsJpTRspm/PYwAW9Ei
9fiphjLRPA4odao+hcih6fQ0AZij5ABdPvieAM/yBaVKn78W+fEPH+uuXit/ccEI
gBYkX2H4CO84Zo2l3hrUtKgFPnGfFvghbCZhFXFbffFTYkY8l2AC4n5rae0zIb0C
p5Lf7Agp3LkUqB6gkkMcoqJFlQKBgQD/AfTmoCMtl3yW1MY+jFrrfNhh/RmHu5QX
xcR48qj0tcn6bPmyinWmPQR0r8wr1hWlAu8IokjZapZBzz3rp9beXEMNVSVq5qZg
H5VQZ4DqY11JfZk9yh0vnxV+Li9C83iUj0E4W98JIlkD91COSyA7suU6l6LjoPiq
8qEEipu1dwKBgAStVvE4SldBTs6LAv9gQ8aHw+Xk/JrMicynNawPSCjnhzBnyaIP
Jzlp5rRybC2oME6yMJYOGcrgTpg9locmkkmyIeyZsLM7RL7uQTXJRjKkY/e0qsFu
tOvjUtVvDyKJpb55eQtVlQ9nj60dk/LDguMwd5DssDW6hrDDdNTSW8hpAoGBAOcr
y+piU2GaSYymeMztCeMeuz4hZsqARqFCXHjUakvknKRTtAyhrkO0Xty1HV7D5b1A
KpdmHqpSEMK578U40vWjJ/nnLVN6omrTVtWb7ucMit37aTb1iX3JNn+7uIZ2FuJ9
9z7zMf6iz5Vj1vgXrLHR3DJAkp7OJ385ErT+PmfDAoGBAMu+QA7j5rd9rpDf7KNl
1E2ZV7MWas4qd+sP85xb5psE5jiI6hqAV2bGRHlfAJH1Cz187162q1+zMFlihj4+
4qawReBw1YhBmOF40WSdVTqrC2R9dGiVUvhqRrw973A7z1JqfU8Nd7EpPeMbCYxf
457HqnrHUzIQKubPrdUdZf/P
-----END PRIVATE KEY-----
)EOF";

const char client_cert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDZDCCAkwCFFavi3vOEzk6bnWWkKGOWse+LWSHMA0GCSqGSIb3DQEBCwUAMG4x
CzAJBgNVBAYTAklUMQ0wCwYDVQQIDARteWNhMQ8wDQYDVQQHDAZOYXBsZXMxDTAL
BgNVBAoMBG15Y2ExEDAOBgNVBAMMB215Y2EuaW8xHjAcBgkqhkiG9w0BCQEWD2pv
am8uOTZAbGl2ZS5pdDAeFw0yMjA5MDIxMDA1NDBaFw0yMjEyMTExMDA1NDBaMG8x
CzAJBgNVBAYTAklUMQ4wDAYDVQQIDAVJdGFseTEPMA0GA1UEBwwGTmFwbGVzMSkw
JwYDVQQKDCBVbml2ZXJzaXRhIGRpIE5hcG9saSBGZWRlcmljbyBJSTEUMBIGA1UE
AwwLMTcyLjIwLjEwLjIwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDr
PDxM+fL7EPw+W8ph2qcJ4R8uT9p/gblKUhGuCZMlodpyQsYUdyz4ZjiajNOrYvJE
K4UHdTDLk2z9L1IidKmoN6kilm5HpVpdBrTge8AKIrCmFe85qEmsXx/H+KuI8wIk
NRFWvsmAcspOXr5RI7g4L5jYMtKzfO6ljRKBd1Weu9jPmMhemXewqx5I2Y1oUgtm
tNjTtqUKDCAypApgf8rRFuMrr1fq+UUBDtGBplFvTc/EzN24JWnoSbU0VTJVc5/N
+n99Sl0qGVD9UhMlJ08cz776MR3HpRQtF3YTSgpoGhTt4tC1l6hIoGtDm5NYCk0a
JiEU2fD1LXCYLmLH17FDAgMBAAEwDQYJKoZIhvcNAQELBQADggEBAFpVNRlj54Gr
dSchMH2eu9YVLhP8n0R3rvU/WX0DQq7nF/+GTjSJeX3CQIibZMwgLyzcoFCchVTD
CGESdWVkql87Bk0EdjL9bgAFG7WOw18WqYXlLyjSv2Gd305K+adtunYb1HkdsOfT
f8o++ojHRSECOdI9CZn++5ayx2BTO8UVCT8xf9eitGqQJSnUzmM7pkJzYrpHf6wj
6R9EhftuhWVKckp1LubIGrBK4RtB/qfGwruF3eWiiqSa8z4GcTeMLac6rRDkgb6k
QW9MWDP8HoKYIN6l+hemd93lKkx4sY3CBQo3b7OrblQP+DoVZHpIcfeO1iYO3gwx
lwRnleoYWp8=
-----END CERTIFICATE-----
)EOF";

static const char ca_cert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDvTCCAqWgAwIBAgIUI4dkKiMl/6flh91AN3CJEmAGZHAwDQYJKoZIhvcNAQEL
BQAwbjELMAkGA1UEBhMCSVQxDTALBgNVBAgMBG15Y2ExDzANBgNVBAcMBk5hcGxl
czENMAsGA1UECgwEbXljYTEQMA4GA1UEAwwHbXljYS5pbzEeMBwGCSqGSIb3DQEJ
ARYPam9qby45NkBsaXZlLml0MB4XDTIyMDkwMjA4NTgzNFoXDTIzMDkwMjA4NTgz
NFowbjELMAkGA1UEBhMCSVQxDTALBgNVBAgMBG15Y2ExDzANBgNVBAcMBk5hcGxl
czENMAsGA1UECgwEbXljYTEQMA4GA1UEAwwHbXljYS5pbzEeMBwGCSqGSIb3DQEJ
ARYPam9qby45NkBsaXZlLml0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKC
AQEA7DH0MousujMlgp05DSMB35Uyt5frHz/Nsa8FOJSCuNgS2WbrNrar4KlHI6sl
Kz8Vgdz8A0XwBoLXk8SCd0Fk2x2ltGx1VlandG/vnTY+pb+bp/tPdfXEOEEVC9+0
ytIWTYGXl5mdVzJSG8MZ5PHhQuNbTCuuDEBgdM2+xTNmlLt8huHnFpdsxtYYn1q5
b5lgw0rL3vEBlrum01kEvb33ZJ9MTutvHU6DVOMndLsJKIDmyf24Js248XAqfwRx
IGG03s6YCRZCpehZkoxVJ66AMbP4J2snBeMrVOWOg67Y/OEcIhvgxYTDVoWtm+9m
IUhni116WX6N29fMCUxKFxsICQIDAQABo1MwUTAdBgNVHQ4EFgQUEvhhKA+SGK1i
/QbSzAzroJ1wUJcwHwYDVR0jBBgwFoAUEvhhKA+SGK1i/QbSzAzroJ1wUJcwDwYD
VR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAoyoNfhGPup5WN3rekFUx
sxHuyoh9b43MoGaHMyjCpbCd6w59zmME/sjojJql1BM8VTV34fnKyUWHPD+/h+l/
kYeoPQmZUmQo/R38H3FtjLcg9jH+RXi70k+TDhaj8Z6TxoJvKr02u4WF0NL/RUGz
db5tWjvZ7fCqTju/63vL+J6CoORiUxYOsmeXxDGMVKV9fnrFVrTfWF6HJtfNvju2
Y5LZaAdn/Hzq1nIlKypITadZgLqNbHE/+WScOPMew4m2YyikHulJHXenalOg2PKY
se0T2fLufOyd5jOqYe6rLSH/rNiJtbf40wthM05dITiY6hffnw2aMTVK+L7ELTZg
8A==
-----END CERTIFICATE-----
)EOF";


const char* ssid = "";
const char* password = "casacasa";
const char* mqtt_server = "";
const char* mqtt_username = "USER2";
const char* mqtt_password = "plutozzo";