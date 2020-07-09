# Lajittelubotti
Laite, mikä osaisi lähteä pisteestä A, omatoimisesti kulkea sille merkittyä reittiä pitkin pisteeseen B. Palata tämän jälkeen pisteeseen A, odottaa ja aloittaa kierros alusta. 

## Arduino IDE (C/C++)
Laitteen ohjelmointiin oli käytetty Arduino IDE-ohjelmistoa (Arduino IDE-ohjelmisto), mikä on Arduinon oma kehitysalusta. Ohjelmointikielenä laitteelle toimi C/C++ pohjainen Arduinolle kehitetty kieli.

## Värisensorin ohjelmointi (TCS 3200)

Kyseisessä esimerkissä Arduino IDE:n sarjamonitoriin tulostuu värisensorin Arduinolle lähettämiä lukuja. Mitä suurempi luku on, sitä enemmän sensori havaitsee kyseisen väristä valoa.

## Laitteen toimintojen ohjelmointi 

Laitteen koodi koostuu yhdestä main loopista missä laite aluksi hakee päätöksentekoon tarvittavan datan värisensorilta. 
Kaiken väridatan mentyä listaan laite käy listan läpi ja if-lauseiden avulla tekee päätöksen mitä tehdä. Ohjelman päätöksenteko-osiossa laite käyttää viittä eri parametria, punaisen valon määrä, vihreän valon määrä, sinisen valon määrä, ”reverse” (parametri mikä kertoo kumpaan suuntaan laite kulkee rataansa pitkin) ja ”onGreen”. 

Ohjelman päätöksenteko-osio on suhteellisen yksinkertainen ja koostuu seitsemästä if-else lauseesta. Lauseissa verrataan punaisen, vihreän ja sinisen valon määriä keskenään. Lauseissa tarkastetaan myös, että tietyn värisen valon määrä ylittää tietyn kynnyksen ja laitteen sen hetkinen kulkusuunta. Vihreällä ollessaan laitteella on lisäparametrina painikkeen painaminen.  
Kun laite on vihreällä viivalla ja painetaan nappia, laite kääntyy ympäri ja punaisen ja sinisen kääntymissuunnat vaihtuvat vastakkaisiksi. 
