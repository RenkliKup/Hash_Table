#include <iostream>
using namespace std;

struct hashh
{
	int *dizi;
	int boyut = 25;
	int cnt;
};
int hesapla(hashh *anh,int x)
{
	return x % anh->boyut;
}

hashh* tanimla()
{
	hashh* h = new hashh;
	h->dizi = new int[h->boyut];
	int i = 0;
	while (i < h->boyut)
	{
		h->dizi[i] = 0;
		i++;
	}
	h->cnt = 0;
	return h;
}
hashh* insert(hashh *h, int x)
{
	if (h->cnt == h->boyut)
	{
		cout << "hash dolu";
	}
	else
	{
		int indis = hesapla(h, x);
		while (h->dizi[indis] != 0 && h->dizi[indis] != -1)
		{
			indis++;
			if (indis == h->boyut)
			{
				indis = 0;
			}
		}
		h->dizi[indis] = x;
		h->cnt++;
		return h;
	}
}

hashh * del(hashh* h, int x)
{
	if (h->cnt == h->boyut)
	{
		cout << "hash dolu";
	}
	else
	{
		int indis = hesapla(h, x);
		while (h->dizi[indis] != x && h->dizi[indis] == -1)
		{
			indis++;
			if (indis == h->boyut)
			{
				indis = 0;
			}
			if (h->cnt == h->boyut)
			{
				break;
			}
		}

		if (h->dizi[indis] == x)
		{
			h->dizi[indis] = -1;
		}
		else
		{
			cout << "aranan eleman yok";
		}
		return h;
			
	}
}
void yazdir(hashh*h)
{
	int i = 0;
	while (i < h->boyut)
	{
		cout << i << ". indis " << h->dizi[i]<<endl;
		i++;
	}
	system("pause");
}

int main()
{
	hashh* h = tanimla();
	yazdir(h);
	h = insert(h, 25);
	yazdir(h);
	h = insert(h, 24);
	yazdir(h);
	h = insert(h, 24);
	yazdir(h);
	h = del(h, 25);
	yazdir(h);
	h = del(h, 24);
	yazdir(h);
	h = del(h, 24);
	yazdir(h);
	


}