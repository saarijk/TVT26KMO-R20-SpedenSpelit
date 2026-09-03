# GitHubin kanssa työskentely

## 1. Forkin asennus ja kirjautuminen

**1.1 Asenna Fork**

Lataa ja asenna [Fork-sovellus](https://git-fork.com/) omalle tietokoneellesi.

**1.2 Lisää GitHub-tunnus Forkiin**

1. Avaa Fork.
2. Mene valikkoon **File > Accounts**.
3. Paina ikkunan alareunassa olevaa **`+`**-nappia.
4. Valitse **GitHub.com** ja kirjaudu GitHub-tunnuksillasi.
5. Fork avaa selaimen, jossa voit hyväksyä sovelluksen käyttöoikeudet.

> **Miksi?** Kun Fork on yhdistetty GitHub-tiliisi, se hoitaa kirjautumisen automaattisesti. Sinun ei tarvitse luoda SSH-avaimia tai syöttää salasanaa joka kerta.

---

## 2. Repositorion kloonaaminen

**2.1 Kopioi repon URL**

1. Mene haluamasi repositorion sivulle GitHubissa.
2. Paina vihreää **`<> Code`**-nappia.
3. Varmista, että **HTTPS**-välilehti on valittuna.
4. Kopioi URL-osoite. Se on muotoa:  
   `https://github.com/käyttäjänimi/repositorio.git`

> Jos sinulla ei ole SSH-avainta luotuna, käytä aina HTTPS-versiota.

**2.2 Kloonaa Forkissa**

1. Avaa Fork (jos et ole jo tehnyt niin).
2. Mene valikkoon **File > Clone** tai paina **`CTRL + N`** (Windows) / **`CMD + N`** (Mac).
3. Liitä kopioimasi URL-osoite sopivaan kenttään.
4. Valitse **Parent Folder** eli kansio, johon repositorio ladataan.
5. Paina **"Test Connection"** varmistaaksesi, että yhteys GitHubiin toimii.
6. Paina **"Clone"**.

> Jos kloonaus epäonnistuu, yleisin syy on, ettei Fork voi kirjoittaa valitsemaasi kansioon. Vaihda kohdekansio ja kokeile uudestaan.

---

## 3. Uuden haaran luominen

> Haara (branch) on kuin "rinnakkaistodellisuus" koodille. Työskentelemällä omassa haarassa voit tehdä muutoksia rikkomatta pääversion (`main`) toimivuutta.

**3.1 Tarkista, että olet oikeassa haarassa**

1. Forkin vasemmassa sarakkeessa näkyvät **Branches** ja **Remotes**.
2. Avaa **Branches**-valikko. `main`-haaran pitäisi olla valittuna.
3. Kun klikkaat `main`-haaraa, oikeanpuoleisessa näkymässä näet kaikki kyseiseen haaraan tehdyt commitit ja niiden tekijät.

**3.2 Luo uusi haara**

1. **Oikea-klikkaa** `main`-haaraa vasemmassa sarakkeessa.
2. Valitse **"New Branch"**.
3. Anna haaralle kuvaava nimi, esimerkiksi:
   - `update-readme` (päivität README-tiedostoa)
   - `refactor-code` (koodin parantaminen/siistiminen)
   - `add-new-feature` (lisäät uuden ominaisuuden)
4. Jos haluat siirtyä automaattisesti uuteen haaraan, varmista, että **"Check out after create"** on valittuna.
5. Paina **"Create Branch"**.

> **Tärkeää:** Kun työskentelet uudessa haarassa, kaikki tekemäsi muutokset näkyvät _vain tässä haarassa_. `main`-haara pysyy ennallaan.

---

## 4. Koodin muokkaaminen

**4.1 Avaa koodi omassa IDE:ssäsi**

1. Avaa haluamasi koodieditori (esim. VS Code).
2. Avaa kloonattu repositorio editorissa.
3. Jos loit uuden haaran, VS Code näyttää alareunassa, millä haaralla olet (esim. `update-readme`).

**4.2 Tee muutokset**

- Muokkaa, lisää tai poista tiedostoja tarpeesi mukaan.
- Tallenna muutokset painamalla **`CTRL + S`** (Windows) / **`CMD + S`** (Mac).

---

## 5. Muutosten tallentaminen ja lähettäminen

Kun olet tyytyväinen tekemiisi muutoksiin, on aika tallentaa ne Gitin versionhallintaan ja lähettää ne GitHubiin.

**5.1 Tallenna muutokset**

1. Mene takaisin Fork-sovellukseen.
2. Vasemmassa sarakkeessa näkyy **"Local Changes"** ja alla lista muuttuneista tiedostoista.
3. Valitse, mitkä tiedostot haluat sisällyttää seuraavaan tallennukseen klikkaamalla tiedostoa ja sitten tiedostojen tyläpuolella olevaa **`Stage`**-nappia. Tiedosto siirtyy "Staged"-alueelle.

**5.2 Tee commit (tallenna muutoshistoriaan)**

1. Kirjoita **Commit-viesti**.
2. Hyvä commit-viesti kertoo _mitä_ muutit, ei _miten_. Esimerkiksi:
   - feat: added resetting functionality
   - fix: corrected broken link
   - refactor: simplified logic
3. Paina **"Commit"**.

**5.3 Puskaa muutokset GitHubiin**

1. Paina **"Push"**-nappia.
2. Muutokset lähetetään _omaan_ GitHub-repositorioosi (forkkiisi).

> **HOX**. Jos useampi henkilö työstää koodia samaan aikaan, oma koodaussessio kannattaa aina aloittaa sillä että hakee viimeisimmät muutokset GitHubista. Tämä tapahtuu **Fetch** ja **Pull** valintojen avulla. Fetch tarkistaa onko repossa uusia muutoksia, ja Pull tarkistaa ja lataa uudet muutokset omalle laitteelle.

---

## 6. Muutosten tarkistus ja yhdistäminen

Pushaamisen jälkeen muutokset näkyvät GitHubissa, mutta ne eivät vielä ole osa pääkoodia. Ennen kuin muutokset yhdistetään (merge), ne voidaan tarkistaa ja testata, ettei niistä aiheudu ongelmia muun koodin kanssa. GitHub ilmoittaa, mitkä tiedostot ja rivit ovat ristiriidassa. Kun ne on korjattu ja muutokset hyväksytty, uusi koodi yhdistetään osaksi päähaaraa.
