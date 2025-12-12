#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char*ad;    //kitap adi dinamik bellek max50
    char*yazar;    //yazar adi dinamik bellek max40
    unsigned short kod; // hangi kategoriye ait oldugu
    float fiyat; //kitabin fiyati
    int yil; //basim yili
} Kitap;


typedef struct {
    char* ad; // kategori adi max 30
    unsigned short kod;  // kategori kodu
    Kitap*kategoriKitaplar;
    int kitapSayisi;  //dizideki anlik mevcut kitap
    int kapasite; //diznin o anki max kapasitesi
}Kategori;


Kategori kategoriOlustur(char*ad,unsigned short kod,Kategori*kategoriDizi){
    Kategori k={ad, kod};
    kategoriDizi=(Kategori*)realloc(kategoriDizi,sizeof(*kategoriDizi)+sizeof(Kategori) );
    kategoriDizi[sizeof(*kategoriDizi)/sizeof(Kategori)]=k;
    return k;
}



Kitap kitapOlustur(char* ad, char* yazar, unsigned short kod, float fiyat, int yil) {
    Kitap k = {ad, yazar, kod, fiyat, yil};
    return k;
}

void  KitapEkle(Kategori *kategoriDizi, int*kategoriSayisi, Kitap yeniKitap){
    
        // kategori kodu ile kitaptaki kategori kodu eslesiyorsa kategori dizisinin son elemanina kitap ekle
        
        
        for (int i=0; i<*kategoriSayisi; i++) {
            printf("%d %d\n",kategoriDizi[i].kod,yeniKitap.kod);
            if (kategoriDizi[i].kod==yeniKitap.kod) {
                printf("kodlar ayni\n");
            if (kategoriDizi[i].kapasite<=kategoriDizi[i].kitapSayisi) {
                printf("%d %d\n",kategoriDizi[i].kapasite,kategoriDizi[i].kitapSayisi);
                kategoriDizi[i].kapasite=kategoriDizi[i].kitapSayisi+1;
                kategoriDizi[i].kategoriKitaplar=(Kitap*)realloc(kategoriDizi[i].kategoriKitaplar,kategoriDizi[i].kapasite*sizeof(Kitap));
                kategoriDizi[i].kategoriKitaplar[kategoriDizi[i].kitapSayisi]=yeniKitap;
               
                //kategorideki kitaplar arrayi doluysa yeniden boyutlandir
                printf("%s\n",kategoriDizi[i].kategoriKitaplar[kategoriDizi[i].kitapSayisi].ad);
                kategoriDizi[i].kitapSayisi++;
            } else {
                kategoriDizi[i].kategoriKitaplar[kategoriDizi[i].kitapSayisi]=yeniKitap;
                kategoriDizi[i].kitapSayisi++;
              
            }
        }
           
    }
    
}

void KitapBilgileriniYazdir(Kitap *kitap) {
    printf("--- Kitap Bilgileri ---\n");
    printf("Kitap Adi : %s\n", kitap->ad);
    printf("    Yazar : %s\n", kitap->yazar);
    printf("      Kod : %hu\n", kitap->kod);
    printf("    Fiyat : %.2f TL\n", kitap->fiyat);
    printf("-----------------------\n");
}

void KategoriBilgileriniYazdir(Kategori *kategori){
    printf("-----------Kategori Bilgileri---------\n");
    printf("             Katagori Adi: %s\n", kategori->ad);
    printf("            Katagori kodu: %d\n", kategori->kod);
    printf("Katagorideki kitap sayisi: %d\n", kategori->kitapSayisi);
    printf("--------------------------------------\n");
}

void  TumKategorileriYazdir(Kategori *kategoriDizi, int kategoriSayisi){
    for (int i=0; i<kategoriSayisi; i++) {
        printf("-------Katagoriler-------------------\n");
        printf(" %d. Kategori Adi: %s\n",i+1,kategoriDizi[i].ad);
        printf("------Kitap Adlari-------\n");
        for (int j=0; j<kategoriDizi[i].kitapSayisi; j++) {
            printf("%d. Kitap adi: %s\t Fiyati: %f\n",j+1,kategoriDizi[i].kategoriKitaplar[j].ad,kategoriDizi[i].kategoriKitaplar[j].fiyat);
        }
        printf("-------------------------------------\n");
    }
}
int FiyatOrtalamasiHesapla(Kategori *kategori){
    int toplam=0;
    for (int i=0; i<kategori->kitapSayisi; i++) {
        toplam+=kategori->kategoriKitaplar[i].fiyat;
    }
    return toplam/kategori->kitapSayisi;
}
 
void OrtalamaUstuKitaplariListele(Kategori *kategori){

    printf("----Ortalama ustu fiyata sahip kitaplar----\n");
    for (int i=0; i<kategori->kitapSayisi; i++) {
        if(kategori->kategoriKitaplar[i].fiyat>FiyatOrtalamasiHesapla(kategori)){
            printf("   %s\n",kategori->kategoriKitaplar[i].ad);
        }
    }
    printf("--------------------------------------------\n");
}

void EnPahaliKitaplariYazdir(Kategori *kategoriDizi, int kategoriSayisi){
    for(int i=0;i<kategoriSayisi;i++){
        printf("%s:\t",kategoriDizi[i].ad);
        int fiyat=0;
        char*enPahaliKitap="";
        for (int j=0; j<kategoriDizi[i].kitapSayisi; j++) {
            if (kategoriDizi[i].kategoriKitaplar[j].fiyat>fiyat) {//eger kategorideki i-1. kitap'in fiyati fiyat degiskeninden yuksekse kitabin fiyati fiyat degiskenine ataniyor degilse ismi enPahaliKitap degiskenine ataniyor.
                fiyat=kategoriDizi[i].kategoriKitaplar[j].fiyat;
            }else{
                strcmp(enPahaliKitap, kategoriDizi[i].kategoriKitaplar[j].ad);
            }
            printf("Kitap Adi: %s-Fiyati:%d\n",enPahaliKitap,fiyat);
        }
    }
}

void EskiKitapFiyatGuncelle(Kategori *kategoriDizi, int kategoriSayisi, int yil, float yeniFiyat){
    printf("----Fiyat Guncelle-------\n");
    for (int i=0; i<kategoriSayisi; i++) {
        for (int j=0; j<kategoriDizi[i].kitapSayisi; j++) {
            if(kategoriDizi[i].kategoriKitaplar[j].yil<yil){
                kategoriDizi[i].kategoriKitaplar[j].fiyat=yeniFiyat;
                printf("%s'nin fiyati guncellendi\t Yeni Fiyat: %f\n",kategoriDizi[i].kategoriKitaplar[j].ad,kategoriDizi[i].kategoriKitaplar[j].fiyat);
                
            }
        }
    }
    printf("------------------------\n");
}

void DiziyDosyayaYaz(Kategori *kategoriDizi, int kategoriSayisi){
    FILE*kategoriFile = fopen("kategoriler.txt", "w");
    FILE*kitapFile=fopen("kitaplar.txt","w");
    printf("dosya olustu\n");
    printf("-ddy-%s\n",kategoriDizi[0].kategoriKitaplar[kategoriDizi[0].kitapSayisi-1].ad);
    for (int i=0; i<kategoriSayisi; i++) {
        fprintf(kategoriFile,"%s %hu \n",kategoriDizi[i].ad,kategoriDizi[i].kod);
        for (int j=0; j<kategoriDizi[i].kitapSayisi; j++) {
            fprintf(kitapFile,"%s %s %hu %f %d\n",kategoriDizi[i].kategoriKitaplar[j].ad,kategoriDizi[i].kategoriKitaplar[j].yazar,kategoriDizi[i].kategoriKitaplar[j].kod,kategoriDizi[i].kategoriKitaplar[j].fiyat,kategoriDizi[i].kategoriKitaplar[j].yil);
        }
    }

    fclose(kitapFile);
    fclose(kategoriFile);
}

void DosyadanDiziyeAktar(Kategori **kategoriDiziPtr, int *kategoriSayisiPtr){
    Kategori *kategoriDizi=(Kategori*)malloc((*kategoriSayisiPtr) *sizeof(Kategori));
   
    FILE*kategoriFile = fopen("kategoriler.txt", "r");
    FILE*kitapFile=fopen("kitaplar.txt","r");
    
    for (int i=0; i<*kategoriSayisiPtr; i++) {
        kategoriDizi[i].ad=(char*)malloc(50*sizeof(char));
        
        fscanf(kategoriFile, "%s %hu",(kategoriDizi[i]).ad,&kategoriDizi[i].kod);
       
        
        
        //kitap sayisini almak icin baslangic
        char v[50];
        char c[50];
        int g;
        float h;
        int k;
        int sayi=0;
        while (fscanf(kitapFile,"%s %s %u %f %d",v,c,&g,&h,&k)!=EOF) {
            sayi++;
        }
        rewind(kitapFile);
        kategoriDizi[i].kitapSayisi=sayi;
        //bitis
        printf("-%d-",kategoriDizi[i].kitapSayisi);
        kategoriDizi[i].kategoriKitaplar=(Kitap*)malloc(kategoriDizi[i].kitapSayisi*sizeof(Kitap));
        for (int j=0; j<kategoriDizi[i].kitapSayisi; j++) {
            kategoriDizi[i].kategoriKitaplar[j].ad = (char*)malloc(50 * sizeof(char));

             
                kategoriDizi[i].kategoriKitaplar[j].yazar = (char*)malloc(50 * sizeof(char));
            fscanf(kitapFile,"%s %s %hu %f %d",(kategoriDizi[i]).kategoriKitaplar[j].ad,(kategoriDizi[i]).kategoriKitaplar[j].yazar,&kategoriDizi[i].kategoriKitaplar[j].kod,&kategoriDizi[i].kategoriKitaplar[j].fiyat,&kategoriDizi[i].kategoriKitaplar[j].yil);
            
        }
     
    }
    
    *kategoriDiziPtr=(Kategori*)realloc(kategoriDizi,*kategoriSayisiPtr*sizeof(Kategori));

    printf("dizi olustu\n");
    fclose(kitapFile);
    fclose(kategoriFile);
    
}
