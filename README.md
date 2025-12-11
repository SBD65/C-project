# C-project
C ile geliştirilmiş; struct yapıları, dinamik bellek yönetimi (malloc/realloc) ve dosya işlemleri kullanan kapsamlı Kütüphane Yönetim Sistemi.
## 🚀 Özellikler

Bu sistem aşağıdaki temel işlevleri yerine getirir:

* **Veri Yönetimi:** Kitap ve kategori ekleme, düzenleme.
* **Dinamik Bellek:** `malloc` ve `realloc` kullanılarak çalışma zamanında (runtime) genişleyebilen dinamik dizi yapısı.
* **Dosya İşlemleri:** Verilerin `kategoriler.txt` ve `kitaplar.txt` dosyalarına kaydedilmesi ve program açılışında bu dosyalardan geri yüklenmesi.
* **Raporlama:**
    * Kategori bazlı kitap listeleme.
    * Ortalama fiyat hesabı.
    * Ortalamanın üzerindeki fiyata sahip kitapların listelenmesi.
    * En pahalı kitabın tespiti.
* **Güncelleme:** Belirli bir yıldan eski kitapların fiyatlarının toplu güncellenmesi.

## 🛠️ Teknik Detaylar

Proje geliştirilirken aşağıdaki C konseptleri aktif olarak kullanılmıştır:

* **Structs (Yapılar):** Kitap ve Kategori veri modelleri için.
* **Pointers & Dynamic Memory Allocation:** Bellek sızıntılarını önlemek ve verimli alan kullanımı için `malloc`, `realloc` ve `free` kullanımı.
* **File I/O:** `fscanf` ve `fprintf` ile veri kalıcılığı (Persistence).
* **Modular Design:** Kodun okunabilirliğini artırmak için fonksiyonlar `Proje1.c` ve `Proje1.h` dosyalarına ayrılmıştır.
* **Makefile:** Derleme sürecini otomatize etmek için yapılandırma dosyası->bu dosya için yapay zeka kullandım.

## ⚙️ Kurulum ve Çalıştırma

Projede **Makefile** bulunduğu için derleme işlemi oldukça basittir. Terminalde proje dizinine geldikten sonra şu komutları kullanabilirsiniz:

**1. Projeyi Derlemek için:**
```bash
make  
