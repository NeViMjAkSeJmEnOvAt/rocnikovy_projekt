# Ročníkový projekt - část 1. Hrubý návrh

I. Cíl projektu (03.06.2021)
----------------------------
### Hlavní informace
- Vyvoření GPS sledovače (převážně pro psy) + jeho lokátor 
- Velikost sledovače by měla být maximálně velikosti mobilního telefonu (aby bylo možné jej umístit na jeho obojek, případně někde do kapsy)
- Skládat by se měl ze dvou částí (sledovač, lokátor)
- Sledovač - bude napájen baterií, krabička o menší velikosti, vysílá signál z místa na kterém se nachází
- Lokátor - na displeji se bude zobrazovat: směr k pozici, vzádlenost, síla baterie, síla signálu
### Problémy
- Znovu se naučit jazyk na programování mikrokontrolerů (wiring)
- Zjistit jaké technologie použít
- Zjistit a nakoupit hardware (porovnat ceny Českých a zahraničních obchodů)
- Vytvořit 3d model krabičky pro celý hardware (Late game) >> poté vytisknu na 3d tiskárně (Ender 3 V2)

II. Informace získané ve škole (03.06.2021)
-------------------------------------------
### Informace k projektu
- Zdroje (KONKURENCE, zdroje co pouzivame) 
- Problémy se kterymi sme se setkali
- 14 stránek
- Použití (ki cad)
- projekt nemusí být na 100% funkční, musí být vidět postup
- jak debugovat esp - 
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


Odkazy a použíté technologie:
-------
* Markdown - [wikipedie](https://cs.wikipedia.org/wiki/Markdown)
* Micropython - [Micropython](https://randomnerdtutorials.com/micropython-esp32-esp8266-vs-code-pymakr/),[MInstalace](https://blog.iservery.com/2020/04/06/instalace-micropython-a-vscode/)
* esp32 debugger - [Debugger](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/jtag-debugging/using-debugger.html), [Github](https://github.com/maakbaas/esp8266-iot-framework)
