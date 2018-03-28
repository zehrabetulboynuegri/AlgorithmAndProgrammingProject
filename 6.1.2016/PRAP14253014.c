// 14253014-ZEHRA BETÜL BOYNUEÐRÝ 
#include<string.h>
#include<stdio.h>
struct takimlarin_bilgisi {
	int takimNumarasi;
	char takim_adi[20], takim_adiDevami[20];
	int puan;
	int macSayisi, galibiyetSayisi, beraberlikSayisi, maglubiyetSayisi;
	int Attigi_golS, Yedigi_golS;
};
struct futbolcularin_bilgisi {
	int futblocuNumarasi, futbolcuTakimNumarasi;
	char futbolcu_adi[30], futbolcu_soyadi[30];
	int AttigiGolSayisi;
	int KendiKalesineAttigiGolSayisi;

};
struct maclarin_bilgisi {
	int macnumarasi, evSahibiTakimNu, deplasmanTakimNu;
	int ev_sahibinin_gol_sayisi, dep_gol_sayisi;

};
struct gollerin_bilgisi {
	int macnumarasi, goldk, goluAtanTakimNumarasi, goluAtanFutbolcuNumarasi;
};

void main() {
	FILE *d1, *d2, *d3, *d4, *d5, *d6;


	struct gollerin_bilgisi goller[1500];
	struct futbolcularin_bilgisi futbolcu[200];
	struct maclarin_bilgisi maclar[500];
	struct takimlarin_bilgisi takimlar[100];
	int i = 0, k = 0, m = 0, max_golSayisi = 0;
	int gol_sayisi = 0, golSayisi = 0, golKrali[50], golKralininAttigiGolSayisi = 0;

	int o = 0;	int t = 0;
	d1 = fopen("goller.txt", "r");
	d2 = fopen("futbolcular.txt", "r");
	d3 = fopen("takimlar.txt", "r");
	d4 = fopen("maclar.txt", "r");
	d5 = fopen("puandurumu.txt", "w");
	d6 = fopen("hattricks.txt", "w");
	if (d1 == NULL, d2 == NULL, d3 == NULL, d4 == NULL, d5 == NULL, d6 == NULL)
	{
		printf("DOSYA BULUNAMADI!");
	}
	else
		while (fscanf(d2, "%d" "%d" "%s" "%s", &futbolcu[t].futblocuNumarasi, &futbolcu[t].futbolcuTakimNumarasi, futbolcu[t].futbolcu_adi, futbolcu[t].futbolcu_soyadi) != EOF)
		{

			t++;

		}
	i = t++;
	/*Ligde en çok golün hangi devrede atýldýðýný buldurma*/

	while (fscanf(d1, "%d" "%d" "%d" "%d", &goller[o].macnumarasi, &goller[o].goldk, &goller[o].goluAtanTakimNumarasi, &goller[o].goluAtanFutbolcuNumarasi) != EOF)
	{

		if (goller[o].goldk >= 0 && goller[o].goldk <= 45)
		{
			gol_sayisi++;
		}

		else {
			golSayisi++;
		}

	

	}
	if (gol_sayisi > golSayisi)
	{
		printf("Ligde en cok gol birinci devrede atilmistir.");

	}
	else if (gol_sayisi == golSayisi)
	{
		printf("Ligde birinci devrede atilan gol sayisi ile ikinci devrede atilan gol sayisi esittir.");
	}
	else {
		printf("Ligde en cok gol ikinci devrede atilmistir.");
	}
	printf("\nBirinci devre atilan gol sayisi:%d\nIkinci devre atilan gol sayisi:%d", gol_sayisi, golSayisi);

	/****************Gol kralinin adýný ekrana yazdýrmak icin***************/


	int  max, q = 0, syc = 0;

	d1 = fopen("goller.txt", "r");
	for (k = 0; k < i; k++)

	{


		futbolcu[k].AttigiGolSayisi = 0;
		futbolcu[k].KendiKalesineAttigiGolSayisi = 0;


		while (fscanf(d1, "%d" "%d" "%d" "%d", &goller[k].macnumarasi, &goller[k].goldk, &goller[k].goluAtanTakimNumarasi, &goller[k].goluAtanFutbolcuNumarasi) != EOF)
		{

			if (k == goller[k].goluAtanFutbolcuNumarasi)
			{
				if (futbolcu[k].futbolcuTakimNumarasi == goller[k].goluAtanTakimNumarasi)
				{

					futbolcu[k].AttigiGolSayisi++;
				}
				else if (futbolcu[k].futbolcuTakimNumarasi != goller[k].goluAtanTakimNumarasi)

				{
					futbolcu[k].KendiKalesineAttigiGolSayisi++;
				}


			}

		}



		d1 = fopen("goller.txt", "r");
	}

	/**************************Kendi kalesine en çok gol atan futbolcunun adýný ekrana yazdýrmak****************/
	int Max, sayac = 0, Kgol[500], g = 0;

	Max = futbolcu[0].KendiKalesineAttigiGolSayisi;

	for (m = 0; m < i; m++)
	{
		if (Max < futbolcu[m].KendiKalesineAttigiGolSayisi)
		{
			Max = futbolcu[m].KendiKalesineAttigiGolSayisi;

		}


	}
	for (m = 0; m < i; m++)
	{
		if (Max == futbolcu[m].KendiKalesineAttigiGolSayisi)
		{
			Kgol[g] = m;
			g++;
			sayac++;
		}
	}

	printf("\n");
	int f = 0;
	if (g > 1) {
		printf("Kendi kalesine en cok golu(%d) atan futbolcular\n", Max);
		for (g = 0; g < sayac; g++) {



			f = Kgol[g];
			printf("%s %s\n", futbolcu[f].futbolcu_adi, futbolcu[f].futbolcu_soyadi);

		}
	}
	else
	{
		printf("\n");
		printf("Kendi kalesine en cok gol(%d) atan futbolcunun adi:%s %s", Max, futbolcu[f].futbolcu_adi, futbolcu[f].futbolcu_soyadi);

	}


	/**********Gol kralýný ve ya gol krallýgýný paylasan oynucularý buldurma*****************/


	max = futbolcu[0].AttigiGolSayisi;
	for (m = 0; m < i; m++)

	{



		if (max < futbolcu[m].AttigiGolSayisi)
		{
			max = futbolcu[m].AttigiGolSayisi;

			t = m;
		}

	}



	max_golSayisi = max;

	for (m = 0; m < i; m++)
	{
		if (max == futbolcu[m].AttigiGolSayisi)
		{

			syc++;
			golKrali[q] = m;
			q++;



		}
	}

	printf("\n");

	if (q > 1) {
		printf("%d gol atarak gol kralligini paylasan futbolcular:\n", max_golSayisi);
		for (q = 0; q < syc; q++) {



			f = golKrali[q];
			printf("%s %s\n", futbolcu[f].futbolcu_adi, futbolcu[f].futbolcu_soyadi);

		}
	}
	else
	{
		printf("\n");
		printf("%d gol atarak gol krali olan futbolcu:%s %s", max_golSayisi, futbolcu[t].futbolcu_adi, futbolcu[t].futbolcu_soyadi);

	}
	printf("\n");

	/*Gol karallýgýndaki ilk 10 futbolcunun isimlerini ve attigi gol sayýlarýný ekrana yazdýrma ve varsa eðer ilk 10 gol krallýgýný paylasan oynucularýnda adini ekrana yazdirma*/

	int z, j, maxx;
	struct futbolcularin_bilgisi gecici;
	for (z = 0; z < i - 1; z++)
	{
		maxx = z;
		for (j = z; j < i; j++)
		{

			if (futbolcu[j].AttigiGolSayisi>futbolcu[maxx].AttigiGolSayisi)
			{
				maxx = j;
			}

		}
		gecici = futbolcu[z];
		futbolcu[z] = futbolcu[maxx];
		futbolcu[maxx] = gecici;

	}
	int s = 10;
	printf("\nGol kralligindaki ilk 10 siradaki futbolcular\n");
	printf("\n%15s%15s%s", "Futbolcunun Adi-", "Futbolcunun Soyadi-", "Futbolcunun Attigi Gol Sayisi");
	printf("\n");
	for (z = 0; z < 10; z++)
	{
		if (futbolcu[z].AttigiGolSayisi != 0)
			printf("%11s%17s%15d\n", futbolcu[z].futbolcu_adi, futbolcu[z].futbolcu_soyadi, futbolcu[z].AttigiGolSayisi);
	}
	if (futbolcu[s].AttigiGolSayisi != 0)
	{
		if (futbolcu[z].AttigiGolSayisi == futbolcu[s].AttigiGolSayisi)

			printf("%d gol atarak gol kralligindaki ilk 10 u paylasan oyuncular\n", futbolcu[z].AttigiGolSayisi);
		for (s = 10; s < i; s++) {


			if (futbolcu[z].AttigiGolSayisi == futbolcu[s].AttigiGolSayisi)
			{
				printf("%11s%17s%15d\n", futbolcu[s].futbolcu_adi, futbolcu[s].futbolcu_soyadi, futbolcu[s].AttigiGolSayisi);
			}


		}
	}

	printf("\n");

	/*********Puan durumu dosyasýný oluþturma*****************/
	struct gollerin_bilgisi _goller[1500];
	int a = 0, takim_sayisi, b = 0, mac_no, c = 0;
	while (fscanf(d3, "%d" "%s" "%s", &takimlar[a].takimNumarasi, takimlar[a].takim_adi, takimlar[a].takim_adiDevami) != EOF)
	{
		takimlar[a].beraberlikSayisi = 0;
		takimlar[a].maglubiyetSayisi = 0;
		takimlar[a].galibiyetSayisi = 0;
		takimlar[a].Attigi_golS = 0;
		takimlar[a].Yedigi_golS = 0;
		takimlar[a].puan = 0;
		a++;

	}
	d1 = fopen("goller.txt", "r");
	while (fscanf(d1, "%d" "%d" "%d" "%d", &_goller[c].macnumarasi, &_goller[c].goldk, &_goller[c].goluAtanTakimNumarasi, &_goller[c].goluAtanFutbolcuNumarasi) != EOF)
	{
		c++;
	}

	takim_sayisi = a;

	for (a = 0; a < takim_sayisi; a++)
	{
		takimlar[a].macSayisi = 0;
		mac_no = 0;
		b = 0;

		while (fscanf(d4, "%d %d %d", &maclar[b].macnumarasi, &maclar[b].evSahibiTakimNu, &maclar[b].deplasmanTakimNu) != EOF)
		{

			if (maclar[b].evSahibiTakimNu == a || maclar[b].deplasmanTakimNu == a)
			{
				takimlar[a].macSayisi++;
			}
			mac_no++;
			b++;
		}

		d4 = fopen("maclar.txt", "r");
	}



	c = 0;
	b = 0;


	while (fscanf(d4, "%d %d %d", &maclar[b].macnumarasi, &maclar[b].evSahibiTakimNu, &maclar[b].deplasmanTakimNu) != EOF)
	{

		maclar[b].ev_sahibinin_gol_sayisi = 0;
		maclar[b].dep_gol_sayisi = 0;

		while (_goller[c].macnumarasi == b) {


			if (_goller[c].goluAtanTakimNumarasi == maclar[b].evSahibiTakimNu)
			{

				maclar[b].ev_sahibinin_gol_sayisi++;

			}
			else if (_goller[c].goluAtanTakimNumarasi == maclar[b].deplasmanTakimNu)
			{

				maclar[b].dep_gol_sayisi++;
			}


			c++;
		}





		b++;

	}

	int _a;
	fprintf(d6, "%8s%15s%28s%25s%28s\n", "Mac no         ","Ev sahibi takim adi", "Attigi gol sayisi  ", "   Deplesman takiminin adi", "  Attigi gol sayisi");
	for (b = 0; b < mac_no; b++){
	
		a = maclar[b].evSahibiTakimNu;
		_a = maclar[b].deplasmanTakimNu;
		fprintf(d6, "%d %35s%10s%20d%38s%10s%25d\n",b, takimlar[a].takim_adi, takimlar[a].takim_adiDevami, maclar[b].ev_sahibinin_gol_sayisi, takimlar[_a].takim_adi, takimlar[_a].takim_adiDevami, maclar[b].dep_gol_sayisi);
	}


	for (a = 0; a < takim_sayisi; a++)
	{
		takimlar[a].Attigi_golS = 0;
		takimlar[a].Yedigi_golS = 0;
		for (b = 0;b < mac_no;b++) {
			if (maclar[b].evSahibiTakimNu == a)
			{
				takimlar[a].Attigi_golS += maclar[b].ev_sahibinin_gol_sayisi;
				takimlar[a].Yedigi_golS += maclar[b].dep_gol_sayisi;
			}
			if (maclar[b].deplasmanTakimNu == a)
			{
				takimlar[a].Attigi_golS += maclar[b].dep_gol_sayisi;
				takimlar[a].Yedigi_golS += maclar[b].ev_sahibinin_gol_sayisi;
			}
		}
	}

	for (b = 0; b < mac_no; b++)
	{

		if (maclar[b].ev_sahibinin_gol_sayisi == maclar[b].dep_gol_sayisi)

		{
			a = maclar[b].evSahibiTakimNu;
			takimlar[a].beraberlikSayisi++;
			a = maclar[b].deplasmanTakimNu;
			takimlar[a].beraberlikSayisi++;
		}
		else if (maclar[b].ev_sahibinin_gol_sayisi < maclar[b].dep_gol_sayisi)
		{
			a = maclar[b].evSahibiTakimNu;
			takimlar[a].maglubiyetSayisi++;
			a = maclar[b].deplasmanTakimNu;
			takimlar[a].galibiyetSayisi++;
		}
		else if (maclar[b].ev_sahibinin_gol_sayisi > maclar[b].dep_gol_sayisi)
		{
			a = maclar[b].evSahibiTakimNu;
			takimlar[a].galibiyetSayisi++;
			a = maclar[b].deplasmanTakimNu;
			takimlar[a].maglubiyetSayisi++;
		}

	}

	printf("********Puan durumu*********\n");
	printf("%s%38s%4s%4s%4s%4s%4s%4s\n", "Takim adi", "O", "G", "B", "M", "A", "Y", "P");
	for (a = 0; a < takim_sayisi; a++)
	{
		takimlar[a].puan = takimlar[a].galibiyetSayisi * 3 + takimlar[a].beraberlikSayisi;

		printf("%12s%19s%16d%4d%4d%4d%4d%4d%4d\n", takimlar[a].takim_adi, takimlar[a].takim_adiDevami, takimlar[a].macSayisi, takimlar[a].galibiyetSayisi, takimlar[a].beraberlikSayisi, takimlar[a].maglubiyetSayisi, takimlar[a].Attigi_golS, takimlar[a].Yedigi_golS, takimlar[a].puan);
	}



	struct takimlarin_bilgisi  _gecici;
	int maximum, u;
	for (a = 0; a < takim_sayisi - 1; a++)
	{
		maximum = a;
		for (u = a; u < takim_sayisi; u++)
		{
			if (strcmp(takimlar[u].takim_adi, takimlar[maximum].takim_adi)<0)

				maximum = u;

		}
		_gecici = takimlar[a];
		takimlar[a] = takimlar[maximum];
		takimlar[maximum] = _gecici;
	}
	for (a = 0; a < takim_sayisi - 1; a++)
	{
		maximum = a;
		for (u = a; u < takim_sayisi; u++)
		{
			if (takimlar[u].puan>takimlar[maximum].puan)

				maximum = u;

		}
		_gecici = takimlar[a];
		takimlar[a] = takimlar[maximum];
		takimlar[maximum] = _gecici;
	}


	fprintf(d5, "%s%25s%6s%6s%6s%6s%6s%6s\n", "Takim adi", "O", "G", "B", "M", "A", "Y", "P");
	for (a = 0; a < takim_sayisi; a++)
	{
		fprintf(d5, "%5s%10s%19d%6d%6d%6d%6d%6d%6d\n", takimlar[a].takim_adi, takimlar[a].takim_adiDevami, takimlar[a].macSayisi, takimlar[a].galibiyetSayisi, takimlar[a].beraberlikSayisi, takimlar[a].maglubiyetSayisi, takimlar[a].Attigi_golS, takimlar[a].Yedigi_golS, takimlar[a].puan);
	}







}



