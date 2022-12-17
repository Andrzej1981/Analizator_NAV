#pragma once

#pragma warning(disable : 4996)

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

string Wiersz;
char c;
FILE* plik;
FILE* zapis;
FILE* fbaza;
FILE* fPotrzeby;
FILE* fRaport;
int liczba;

struct Linia
{
	string Nr_cz;
	string Data;
	string Ilosc;
	string Umowa;
	string linijka;
};

struct Linia_produkcyjna
{
	string Nr_czesci;
	string Data;
	string Ilosc_do_produkcji;
	string Umowa;
	string Linijka;
	string Stan_magazynowy;
	string Ilosc_w_produkcji;
	string Gatunek_blachy;
	string Grubosc_blachy;
	string Rev_vendory;
	string Rev_baza;
	string Status_w_bazie;
	string Uwagi;

};

struct Baza
{
	string Nr_czesci;
	string Gatunek_materialu;
	string X;
	string Y;
	string Grubosc_materialu;
	string Ciezar;
	string Data;
	string Obwod_calkowity;
	string Pole_czesci;
	string Cena_ciecia;
	string Cena_materialu;
	string Realna_waga_czesci;
	string Status;
	string Rewizja;
	string Uwagi;
	string AMS;
	string LP;
	string Vendory;
	string Produkt;
};

struct Navision
{
	string Status;
	string Nr_zlecenia;
	string Nr_partii_wyprodukowany;
	string Nr_zapasu_wg_klienta;
	string Opis_szukany;
	string Ksiegowanie_Seryjne;
	string Nr_dokumentu_zewnetrznego;
	string Data_ksiegowania;
	string Data_dokumentu;
	string Nr_zapasu_produkowanego;
	string Ilosc_produkowana;
	string Ilosc_wyprodukowana;
	string Ilosc_do_wydania;
	string Ilosc_wydana;
	string Stan_magazynowy;
	string Ilosc_na_zam_sprzdazy;
	string Tolerancja;
	string Nr_materialu;
	string Ilosc_materialu;
	string Nr_zapasu_zlomu;
	string Ilosc_zlomu;
	string Nr_zapasu_alternatwny;
	string Opis_zapasu;
	string Opis_2_zapasu;
	string Opis_materialu;
	string Opis_2_materialu;
	string Opis_zlomu;
	string Opis_2_zlomu;
	string Opis_zapasu_alternatywnego;
	string Opis_2_zapasu_alternatywnego;
	string Seria_numeracji;
	string Seria_numeracji_ksiegowej;
	string No;
	string Jednostka_miary_zapasu;
	string Jednostka_miary_materialu;
	string Jednostka_zapasu_zlomu;
	string Jednostka_zapasu_alternatywnego;
	string Waga_netto_zapasu;
	string Waga_brutto_zapasu;
	string Procent_zlomu;
	string Dodatek_w_mm;
	string Ilosc_zgodna;
	string Zadana_data_dostawy;
	string Ilosc_niezgodna;
	string Nr_programu;
	string Status_jakosci;

};

Linia P1, P2;
Baza B1;
Navision Nav1;

//---------------------------------------------------------------------------
void Wyczysc_strukture_bazy(Baza& b)
{
	b.Nr_czesci.clear();
	b.Gatunek_materialu.clear();
	b.X.clear();
	b.Y.clear();
	b.Grubosc_materialu.clear();
	b.Ciezar.clear();
	b.Data.clear();
	b.Obwod_calkowity.clear();
	b.Pole_czesci.clear();
	b.Cena_ciecia.clear();
	b.Cena_materialu.clear();
	b.Realna_waga_czesci.clear();
	b.Status.clear();
	b.Rewizja.clear();
	b.Uwagi.clear();
	b.AMS.clear();
	b.LP.clear();
	b.Vendory.clear();
	b.Produkt.clear();
	return;
}
//---------------------------------------------------------------------------
void Wyczysc_strukture_Navision(Navision& Nav)
{
	Nav.Status.clear();
	Nav.Nr_zlecenia.clear();
	Nav.Nr_partii_wyprodukowany.clear();
	Nav.Nr_zapasu_wg_klienta.clear();
	Nav.Opis_szukany.clear();
	Nav.Ksiegowanie_Seryjne.clear();
	Nav.Nr_dokumentu_zewnetrznego.clear();
	Nav.Data_ksiegowania.clear();
	Nav.Data_dokumentu.clear();
	Nav.Nr_zapasu_produkowanego.clear();
	Nav.Ilosc_produkowana.clear();
	Nav.Ilosc_wyprodukowana.clear();
	Nav.Ilosc_do_wydania.clear();
	Nav.Ilosc_wydana.clear();
	Nav.Stan_magazynowy.clear();
	Nav.Ilosc_na_zam_sprzdazy.clear();
	Nav.Tolerancja.clear();
	Nav.Nr_materialu.clear();
	Nav.Ilosc_materialu.clear();
	Nav.Nr_zapasu_zlomu.clear();
	Nav.Ilosc_zlomu.clear();
	Nav.Nr_zapasu_alternatwny.clear();
	Nav.Opis_zapasu.clear();
	Nav.Opis_2_zapasu.clear();
	Nav.Opis_materialu.clear();
	Nav.Opis_zlomu.clear();
	Nav.Opis_2_zlomu.clear();
	Nav.Opis_zapasu_alternatywnego.clear();
	Nav.Opis_2_zapasu_alternatywnego.clear();
	Nav.Seria_numeracji.clear();
	Nav.Seria_numeracji_ksiegowej.clear();
	Nav.No.clear();
	Nav.Jednostka_miary_zapasu.clear();
	Nav.Jednostka_miary_materialu.clear();
	Nav.Jednostka_zapasu_zlomu.clear();
	Nav.Jednostka_zapasu_alternatywnego.clear();
	Nav.Waga_netto_zapasu.clear();
	Nav.Waga_brutto_zapasu.clear();
	Nav.Procent_zlomu.clear();
	Nav.Dodatek_w_mm.clear();
	Nav.Ilosc_zgodna.clear();
	Nav.Zadana_data_dostawy.clear();
	Nav.Ilosc_niezgodna.clear();
	Nav.Nr_programu.clear();
	Nav.Status_jakosci.clear();
	return;
}
//---------------------------------------------------------------------------
int Wczytaj_strukture_Navision(Navision& Nav, FILE* aa)
{
	Wyczysc_strukture_Navision(Nav);

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Status += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_zlecenia += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_partii_wyprodukowany += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_zapasu_wg_klienta += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_szukany += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ksiegowanie_Seryjne += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_dokumentu_zewnetrznego += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Data_ksiegowania += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Data_dokumentu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_zapasu_produkowanego += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_produkowana += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_wyprodukowana += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_do_wydania += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_wydana += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Stan_magazynowy += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_na_zam_sprzdazy += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Tolerancja += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_materialu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_materialu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_zapasu_zlomu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_zlomu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_zapasu_alternatwny += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_zapasu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_2_zapasu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_materialu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_2_materialu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_zlomu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_2_zlomu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_zapasu_alternatywnego += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Opis_2_zapasu_alternatywnego += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Seria_numeracji += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Seria_numeracji_ksiegowej += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.No += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Jednostka_miary_zapasu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Jednostka_miary_materialu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Jednostka_zapasu_zlomu += c;
	} while (!(c == '\t'));


	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Jednostka_zapasu_alternatywnego += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Waga_netto_zapasu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Waga_brutto_zapasu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Procent_zlomu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Dodatek_w_mm += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_zgodna += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Zadana_data_dostawy += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Ilosc_niezgodna += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else Nav.Nr_programu += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\n') {}
		else Nav.Status_jakosci += c;
	} while (!(c == '\n'));


	return 0;
}

//---------------------------------------------------------------------------

int Wczytaj_Linie_Bazy(Baza& b, FILE* aa)
{
	Wyczysc_strukture_bazy(b);

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Nr_czesci += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Gatunek_materialu += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.X += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Y += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Grubosc_materialu += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Ciezar += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Data += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Data += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Obwod_calkowity += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Pole_czesci += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Cena_ciecia += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Cena_materialu += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Realna_waga_czesci = c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Status += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Rewizja += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Uwagi = c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.AMS += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.LP += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else b.Vendory += c;
	} while (!(c == '\t'));
	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\n') {}
		else b.Produkt += c;
	} while (!(c == '\n'));
}



void Zamien()
{
	plik = fopen("Portal.txt", "r");
	zapis = fopen("PoPortal.txt", "w");


	if (zapis == 0)
	{

		return;
	};

	do
	{
		c = fgetc(plik);
		if (c == '\t' || c == '\n') {}
		else Wiersz += c;


		if ((c == '\t') || (c == '\n'))
		{
			fprintf(zapis, "%s\n", Wiersz.data());
			Wiersz.clear();
		};

	} while (c != EOF);

	fclose(plik);
	fclose(zapis);
	return;
}

//---------------------------------------------------------------------------
int Wczytaj_Linie(Linia& p, FILE* aa)
{
	p.Nr_cz.clear();
	p.Data.clear();
	p.Ilosc.clear();
	p.Umowa.clear();
	p.linijka.clear();


	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };

		if (c == '\t') {}
		else p.Nr_cz += c;
	} while (!(c == '\t'));


	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };
		if (c == '\t') {}
		else p.Data += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };
		if (c == '\t') {}
		else p.Ilosc += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };
		if (c == '\t') {}
		else p.Umowa += c;
	} while (!(c == '\t'));

	do
	{
		c = fgetc(aa);
		if (c == EOF) { return 1; };
		if (c == '\n') {}
		else p.linijka += c;
	} while (!(c == '\n'));

	return 0;
};
//---------------------------------------------------------------------------

string intToStr(int n)
{
	string tmp;
	if (n < 0) {
		tmp = "-";
		n = -n;
	}
	if (n > 9)
		tmp += intToStr(n / 10);
	tmp += n % 10 + 48;
	return tmp;
}

//---------------------------------------------------------------------------
void Zapis(Linia& P, FILE* aa)
{
	fprintf(aa, "%s\t%s\t%s\t%s\t%s\n", P.Nr_cz.data(), P.Data.data(), P.Ilosc.data(), P.Umowa.data(), P.linijka.data());
	return;
}

//---------------------------------------------------------------------------

void Sumuj_Portal()
{
	int i = 0;
	plik = fopen("Portal.txt", "r");
	zapis = fopen("Wyniki.txt", "w");

	Wczytaj_Linie(P1, plik);
	Wczytaj_Linie(P2, plik);

	do
	{
		if ((P1.Nr_cz == P2.Nr_cz) && (P1.Umowa == P2.Umowa))
		{
			liczba = atoi(P1.Ilosc.data()) + atoi(P2.Ilosc.data());
			P1.Ilosc = intToStr(liczba);
			i = Wczytaj_Linie(P2, plik);
		}
		else
		{

			Zapis(P1, zapis);
			P1.Nr_cz = P2.Nr_cz;
			P1.Data = P2.Data;
			P1.Ilosc = P2.Ilosc;
			P1.Umowa = P2.Umowa;
			P1.linijka = P2.linijka;
			i = Wczytaj_Linie(P2, plik);
		};

	} while (!i);

	fclose(plik);
	fclose(zapis);

	return;
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void Zapisz_Obliczona_strukture(Linia& P, int i, int l, string s, FILE* aa)
{

	fprintf(aa, "%s\t%s\t%s\t%s\t%s\t%i\t%i\t%s\n", P.Nr_cz.data(), P.Data.data(), P.Ilosc.data(), P.Umowa.data(), P.linijka.data(), i, l, s.data());
	return;
}


void Zrob_w_chuj()
{
	int i = 0;
	int l = 1;
	int ilosc_w_produkcji = 0;
	int ilosc_na_stanie = 0;
	string s;

	plik = fopen("Navision.txt", "r");
	fbaza = fopen("Wyniki.txt", "r");
	zapis = fopen("Obliczone potrzeby na portalu.txt", "w");
	fRaport = fopen("Raport.txt", "w");




	do
	{
		i = Wczytaj_Linie(P1, fbaza);

		printf("Analizuje czesc:%s\n", P1.Nr_cz.data());


		do
		{
			l = Wczytaj_strukture_Navision(Nav1, plik);
			if (P1.Nr_cz == Nav1.Nr_zapasu_wg_klienta)
			{
				if (Nav1.Status == "Otwarty")
				{
					ilosc_w_produkcji += atoi(Nav1.Ilosc_produkowana.data());
					ilosc_na_stanie = atoi(Nav1.Stan_magazynowy.data());
					s += Nav1.Nr_zlecenia.data();
					s += " -Otwarte- ";
					s += Nav1.Ilosc_produkowana.data();
					s += "szt.   ";

					//----Zapis do raportu
					fprintf(fRaport, "%s\n", Nav1.Nr_zapasu_wg_klienta.data());
					fprintf(fRaport, "Ilosc zadana:%s  Data dostawy:%s\n", P1.Ilosc.data(), P1.Data.data());
					fprintf(fRaport, "%s --- %s szt.\n", Nav1.Nr_zlecenia.data(), Nav1.Ilosc_produkowana.data());
					fprintf(fRaport, "%s\n", Nav1.Nr_programu.data());
					fprintf(fRaport, "%s\n\n", Nav1.Nr_zapasu_produkowanego.data());
					//----koniec zapisu do raportu
				};
				if (Nav1.Status == "Zablokowany")
				{
					ilosc_na_stanie = atoi(Nav1.Stan_magazynowy.data());
					s += Nav1.Nr_zlecenia.data();
					s += "- Zablokowane ";
					s += Nav1.Ilosc_wyprodukowana;
					s += "szt.   ";
				};

			};

		} while (!l);


		Zapisz_Obliczona_strukture(P1, ilosc_na_stanie, ilosc_w_produkcji, s, zapis);
		ilosc_na_stanie = 0;
		ilosc_w_produkcji = 0;
		s.clear();
		Wyczysc_strukture_Navision(Nav1);
		P1.Nr_cz.clear();
		P1.Data.clear();
		P1.Ilosc.clear();
		P1.Umowa.clear();
		P1.linijka.clear();
		fclose(plik);
		plik = fopen("Navision.txt", "r");
	} while (!i);

	fclose(fRaport);
	fclose(fbaza);
	fclose(plik);
	fclose(zapis);


	return;
}

//---------------------------------------------------------------------------


