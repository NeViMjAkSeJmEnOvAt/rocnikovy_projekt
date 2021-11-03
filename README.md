# Ročníkový projekt (Sledovací obojek pro psy) - část 1. Hrubý návrh

I. Cíl projektu (03.06.2021)
----------------------------
### Hlavní informace
- Vyvoření GPS sledovače (převážně pro psy) + jeho lokátor 
- Velikost sledovače by měla být maximálně velikosti mobilního telefonu (aby bylo možné jej umístit na jeho obojek, případně někde do kapsy)
- Skládat by se měl ze dvou částí (sledovač, lokátor)
- Sledovač - bude napájen baterií, krabička o menší velikosti, vysílá signál z místa na kterém se nachází
- Lokátor - na displeji se bude zobrazovat: směr k pozici, vzádlenost, síla baterie, síla signálu (old)
- Lokátor - bude dostávat signál pomocí LoRa zařízení, které pak bude zobrazovat na webovém serveru
- esp32 LORA
### Problémy
- Znovu se naučit jazyk na programování mikrokontrolerů (wiring)
- Zjistit jaké technologie použít
- Zjistit a nakoupit hardware (porovnat ceny Českých a zahraničních obchodů)
- Vytvořit 3d model krabičky pro celý hardware (Late game) >> poté vytisknu na 3d tiskárně (Ender 3 V2)
- LoRa Reciever nepřijímá Packety odeslané LoRa Senderem (vyřešeno)
- Zařízení komunikují, pokud se jejich antény dotýkají jinak ne (vyřešeno, špatná frekvence)

II. Informace získané ve škole (03.06.2021)
-------------------------------------------
### Informace k projektu
- Zdroje (KONKURENCE, zdroje co pouzivame) 
- Problémy se kterymi sme se setkali
- 14 stránek
- Použití (ki cad)
- projekt nemusí být na 100% funkční, musí být vidět postup
- jak debugovat esp
- framework
- SPIFFS
- OTA update
### Hodnocení projektu (16.06.2021)
- projekt samotný - __40%__
- dokumentace - __20%__ (všechny informace o projektu, problémy, časové rozvržení, časová náročnost..)
- prezentace - __20%__ ()
- průběžnost - __20%__ (jak se na projektu pracuje postupně)

III. Konkurence (16.06.2021)
-------------------------------------------
- Eshop [Elektro obojky](https://www.elektro-obojky.cz/gps-obojky-pro-psy/)
### Garmin
* [Garmin](https://www.elektro-obojky.cz/gps-obojky-garmin/)
* 6-14.5km
* 9000 - 29000 kč
* dotykový display
* GPS + GLONASS a VHF
* spustitelný alarm + sdílení polohy
* sledování ostatních obojků
* nastavení povoleného rádiusu
* 3D kompas
* upozornění na štěkot psa
* možnost použití vibrace / tónu / impulzu
* 212g
* režim spánku
### Tracker
* [Tracker](https://www.elektro-obojky.cz/gps-obojky-pro-psy-tracker/)
* neomezený dosah
* 15000 - 25000 kč
* Využití 3G a 2G
* sledování ostatních obojků
* přes mobil
### Dogtrace
* [Dogtrace](https://www.elektro-obojky.cz/gps-obojky-dogtrace/)
* 10000 - 20000 kč
* až 20km
* zvukový lokátor
* možných až 13 obojků
* plně vodotěsný
* 40+ hodin výdrž
* kompas
* ukládání bodů na mapě

IV. Předpokládaný Harmonogram (15.09.2021)
-------------------------------------------
### Září
* Sepsat nutné zdroje ✔️
* Objednat hardware ✔️
* Zjistit všechny věci co budou potřeba ✔️

### První polovina Říjnu
* Seznámit se s technologiemi ✔️
* Rozpracovat hardware ✔️

### Druhá polovina Říjnu
* Začít psát kód ✔️
* Sestavit hardware ❌

### První polovina Listopadu
* Pomalu dokončovat kód
* Debugování a chyby
* Udělat návrh obalu 

### Druhá polovina Listopadu
* Finální úpravy
* Zbytek času na to, pokud něco nebudu stíhat
* Vytisknout obal na 3d tiskárně

### První polovina Prosince (Termín 10.12.2021)
* Sepsat dokumentaci
* Poslední testy

IV. Konečný Harmonogram 
-------------------------------------------
* Červen 2021 - udělání Githubu, Získané informace o konkurenci, Cíl projektu
* 15.09.2021 - sepsání hrubého Harmonogramu
* 30.09.2021 - spuštění IDE + první test fungování esp
* 06.10.2021 - Změna IDE + snaha o instalaci SPIFFS
* 12.10.2021 - seznamování se SPIFFS
* 13.10.2021 - SPIFFS funguje, webový server funguje
* 14.10.2021 - úprava kódu, editace webu
* 15.10.2021 - seznamování se s GPS modulem
* 28.10.2021 - zprovoznění LoRa zařízení
* 29.10.2021 - Snaha o komunikaci mezi zařízeními
* 31.10.2021 - Zařízení mezi sebou komunikují 
* 02.11.2021 - Vyřešena komunikace dvou žařízení pomocí LoRa

# Ročníkový projekt (Sledovací obojek pro psy) - část 2. Sestavování

I. Zporvoznění Arduino IDE pro ESP32 (později PlatformIO)
--------------------------------------
* 30.09.2021 - Zprovoznění IDE, pro práci s esp32 a první test funkčnosti
* Spuštění programu na vyhledání sítě, úspěšně splněno
* Vyřešený problém - systémový monitor vypisoval corruptované výsledky, musel sem změnit počet baudů
* Dále test displaye
* Víte informací v adresáři "ESPtest1"

II. Instalace PlatformioIDE + SPIFFS
--------------------------------------
* Změna platformy z Arduino IDE na Platformio IDE ve Visual Studio Code
* 06.10.2021 - Instalace Platformio IDE do Visual Studio Code (pro práci s ESP32)
* Zkouška instalace SPIFFS (Problém s instalací)
* 12.10.2021 - Snaha o spuštění webového serveru na esp32
* 13.10.2021 - webserver funguje, vypis na obrazovku
<div class="row">
  <img src="/images/spiff_webserver/IMG_20211012_222443.jpg" alt="LoRa_Sender" width="300"/>
  <img src="/images/spiff_webserver/IMG_20211012_222452.jpg" alt="LoRa_Sender" width="300"/>
  <img src="/images/spiff_webserver/site.JPG" alt="Stranka" width="375"/>
</div>

III. Komunikace mezi dvěmi LoRa zařízeními
------------------------------------------
* Zařízení komunikují pomocí jednoduchých zpráv
* Problém s tím, že nefunguje využití antény, zařízení komunikují jen, když se antény dotýkají
* problém vyřešen, frekvence zařízení byla jiná, než je daná pro Evropu
* Test zařízení: potvrení komunikace na zhruba 500-800m
* použitá knihovna "heltec.h" -> kvůli Esp od firmy heltec
<div class="row">
  <img src="/images/lora/IMG_20211102_220334.jpg" alt="LoRa_Sender" width="350"/>
  <img src="/images/lora/IMG_20211102_220342.jpg" alt="LoRa_Reciever" width="350"/>
</div>


Odkazy a použíté technologie:
-------
* Markdown - [wikipedie](https://cs.wikipedia.org/wiki/Markdown)
* Micropython - [Micropython](https://randomnerdtutorials.com/micropython-esp32-esp8266-vs-code-pymakr/), [Instalace](https://blog.iservery.com/2020/04/06/instalace-micropython-a-vscode/)
* esp32 debugger - [Debugger](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/jtag-debugging/using-debugger.html), [Github](https://github.com/maakbaas/esp8266-iot-framework)
* esp32 LORA - https://www.ebay.com/itm/173624285281 + gps modul https://www.ebay.com/itm/174930619300
* NMEA - https://en.wikipedia.org/wiki/NMEA_2000
* spiffs - https://randomnerdtutorials.com/esp32-vs-code-platformio-spiffs/
* spiffs webserver - https://randomnerdtutorials.com/esp32-web-server-spiffs-spi-flash-file-system/
* LoRa komunikace - https://github.com/HelTecAutomation/Heltec_ESP32/tree/master/examples/LoRa
* LoRa komunikace 2 - https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/
* Heltec knihovna-priklady - https://github.com/HelTecAutomation/Heltec_ESP32/tree/master/examples/LoRa





* jen si to tady odlozim https://blog.iservery.com/wp-content/uploads/2014/01/Maturitn%C3%AD_ot%C3%A1zky_TVY_n%C3%A1vrh-.pdf
