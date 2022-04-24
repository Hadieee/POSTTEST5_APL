#include <iostream> // Untuk penggunaan fungsi cout, cin, dan endl
#include<conio.h>   // Untuk penggunaan fungsi getch
#include<iomanip> // Digunakan untuk ngerapihin spasi membuat table
using namespace std; // Agar tidak perlu menuliskan "std::"

struct anggota // Terdapat sebuah struct untuk mendeklarasi array dari nama, jenis kelamin, umur dan ketersediaan raket
{
    string nama;
    string kelamin;
    int umur;
    int ketersediaan;
};

// Untuk mendeklarasikan sebuah array data_anggota yang bertipe struct data
struct anggota data_anggota[50]; 

// Untuk keperluan pertambahan indeks array, panjang array, nomor, pilihan, perulangan, penukaran, dan membandingkan
int a, b, c, i, j, n = sizeof(data_anggota)/sizeof(data_anggota[0]), compare, min_index, ditemukan = 0, pilih; 

// Untuk tanya saat ingin keluar dari program serta memilih jenis pengurutan
char tanya, urut; 

// Untuk variabel saat mencari nama
string Nama;

//Prototype
void inputdata();
void lihatdata();
void editdata();
void hapusdata();
void tukar(int y,int z);
void urutan();
void bubble_sort_Umur_Asc(anggota arr[]);
void bubble_sort_Umur_Desc(anggota arr[]);
void bubble_sort_Raket_Asc(anggota arr[]);
void bubble_sort_Raket_Desc(anggota arr[]);
void selection_sort_Umur_Asc(anggota arr[], int n);
void selection_sort_Umur_Desc(anggota arr[], int n);
void selection_sort_Raket_Asc(anggota arr[]);
void selection_sort_Raket_Desc(anggota arr[]);
void insertion_sort_Umur_Asc(anggota arr[], int n);
void insertion_sort_Umur_Desc(anggota arr[], int n);
void insertion_sort_Raket_Asc(anggota arr[], int n);
void insertion_sort_Raket_Desc(anggota arr[], int n);
void tampilan_sorting_Asc();
void tampilan_sorting_Desc();


// Fungsi utama
int main() 
{
    // Terdapat label awal sebagai tempat untuk kembali ke menu utama setelah melakukan eksekusi data
    awal: 
    system("cls");
    system("color 5A");
    cout<<"\n============================= PROGRAM CRUD DATA ANGGOTA =============================";
    cout<<"\n=================================== PILIHAN MENU ====================================\n";
    cout<<"\n\t\t\t\t1. Masukkan data";
    cout<<"\n\t\t\t\t2. Lihat Data";
    cout<<"\n\t\t\t\t3. Edit Data";
    cout<<"\n\t\t\t\t4. Hapus Data";
    cout<<"\n\t\t\t\t5. Sorting Data";
    cout<<"\n\t\t\t\t6. Keluar\n";
    cout<<"\n=====================================================================================\n";
    cout<<"\nMasukkan Pilihan : ";
    pilih = getch();
    switch(pilih)
    {
        case'1':
            // goto yang berfungsi untuk melompat ke baris label
            {system("cls");inputdata();goto awal;break;} 
        case'2':
            // goto yang berfungsi untuk melompat ke baris label
            {system("cls");lihatdata();goto awal;}
        case'3':
            // goto yang berfungsi untuk melompat ke baris label
            {system("cls");editdata();goto awal;}
        case'4':
            // goto yang berfungsi untuk melompat ke baris label
            {system("cls");hapusdata();goto awal;}
        case'5':
            // goto yang berfungsi untuk melompat ke baris label
            {system("cls");urutan();goto awal;}
        case'6':
            {   
                system("cls");
                // Terdapat label Tanya sebagai tempat untuk kembali ke pilihan ingin keluar program ketika salah dalam memilih
                Tanya: 
                
                cout<<"\nApakah anda ingin keluar dari program ? (Y / T) : "<< endl; // Untuk menanyakan user apakah ingin keluar dari program
                tanya = getch();
                switch (tanya)
                {
                    case('y'):
                    case('Y'):
                        system("cls");
                        cout<<"=======================================================================" << endl;
                        cout << "Terimakasih telah menggunakan program ini :) Semoga harimu menyenangkan" << endl;
                        cout<<"======================================================================="; exit(0);

                    case('t'):
                    case('T'):
                        system("cls");goto awal;
                    
                    // Untuk kesalahan dalam memilih
                    default: 
                        cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto Tanya;
                }
                }
        // Untuk kesalahan dalam memilih
        default:
        {
            cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto awal;
        }
    }
}


// Prosedur untuk input data
void inputdata()
{
    system("color 5A");
    cout<<"Nama Panggilan\t\t\t\t: "; getline(cin,data_anggota[a].nama);fflush(stdin);
    cout<<"Jenis Kelamin (L / P)\t\t\t: ";cin>>data_anggota[a].kelamin;fflush(stdin);
    cout<<"Umur\t\t\t\t\t: ";cin>>data_anggota[a].umur;fflush(stdin);
    cout<<"Jumlah ketersediaan Raket\t\t: ";cin>>data_anggota[a].ketersediaan;fflush(stdin);

    // Untuk penambahan indeks array
    a++; 
    cout<<"\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();system("cls");
}


// Prosedur untuk lihat data
void lihatdata() 
{
    system("color 5A");
    cout<<"\n========================================================= Menampilkan Data ===================================================================\n\n";
    cout<<"==============================================================================================================================================\n";
    cout<<"||"<<setw(5)<<"NO"<<setw(5)<<"||"<<setw(25)<<"Nama Panggilan"<<setw(15)<<"||"<<setw(25)<<"Jenis Kelamin"<<setw(15)<<"||"<<setw(10)<<"Umur"<<setw(10)<<"||"<<setw(20)<<"Ketersediaan"<<setw(10)<<"||";
    cout<<"\n==============================================================================================================================================";

    // Variabel j untuk penomoran dalam tabel
    j = 0; 
    for(i=0;i<a;i++)
    {
        j=j+1;
        cout<<"\n";
        cout<<"||"<<setw(4)<<j<<setw(6)<<"||";
        cout<<setw(25)<<data_anggota[i].nama<<setw(15)<<"||";
        cout<<setw(20)<<data_anggota[i].kelamin<<setw(20)<<"||";
        cout<<setw(10)<<data_anggota[i].umur<<setw(10)<<"||";
        cout<<setw(15)<<data_anggota[i].ketersediaan<<setw(15)<<"||";
        cout<<"\n==============================================================================================================================================";
    }
    getch();system("cls");
}


void editdata() // Prosedur untuk edit data
{
    // Terdapat label apa sebagai tempat untuk kembali mengedit data ketika salah dalam memilih pilihan
    apa:
    system("cls");
    system("color 5A");
    cout<<"Masukan nama yang ingin diedit\t\t: "; getline(cin, Nama);

    for( b = 0; b < 50 - 1; b++)
    {
        if (data_anggota[b].nama == Nama)
        {
            cout<<"Nama Panggilan\t\t\t\t: "; getline(cin,data_anggota[b].nama);fflush(stdin);
            cout<<"Jenis Kelamin (Laki-laki / Perempuan)\t: ";cin>>data_anggota[b].kelamin;fflush(stdin);
            cout<<"Umur\t\t\t\t\t: ";cin>>data_anggota[b].umur;fflush(stdin);
            cout<<"Jumlah Ketersediaan Raket\t\t: ";cin>>data_anggota[b].ketersediaan;fflush(stdin);
            cout<<"\n============================================================ Data berhasil diedit ============================================================\n";
            ditemukan++;
            break;
        }
        if(b == 50 - 2)
        {
            cout<<"Nama tidak ditemukan";

             // Untuk menanyakan user apakah ingin mengedit data lagi
            cout<<"\nApakah anda ingin mengedit kembali ? (Y / T) : "<< endl;
            tanya = getch();
            switch (tanya)
            {
                case('y'):
                case('Y'):
                    system("cls");goto apa;

                case('t'):
                case('T'):
                    goto langsung;
                
                // Untuk kesalahan dalam memilih
                default: 
                    cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto apa;
            }
        }       
    }

    // Terdapat label langsung sebagai tempat untuk melihat data ketika sudah tidak ingin mengedit data
    langsung: 
    lihatdata();
}


// Prosedur untuk hapus data
void hapusdata() 
{
    // Terdapat label iya sebagai tempat untuk kembali menghapus data ketika salah dalam memilih pilihan
    iya: 
    system("color 5A");
    cout<<"Masukan nama yang ingin dihapus\t\t: "; getline(cin, Nama);

    for( c = 0; c < 50 - 1; c++)
    {
        if (data_anggota[c].nama == Nama)
        {
            // Variabel a untuk indeks di data
            a--; 
            for(int i=c;i<a;i++)
            {
                data_anggota[i] = data_anggota[i+1];
            }
            system("cls");
            cout<<"\n============================================================ Data berhasil dihapus ============================================================\n";
            ditemukan++;
            break;
        }
        if(c == 50 - 2)
        {
            cout<<"Nama tidak ditemukan";

            // Untuk menanyakan user apakah ingin menghapus data lagi
            cout<<"\nApakah anda ingin mengedit kembali ? (Y / T) : "<< endl; 
            tanya = getch();
            switch (tanya)
            {
                case('y'):
                case('Y'):
                    system("cls");goto iya;

                case('t'):
                case('T'):
                    goto langsungg;
                
                // Untuk kesalahan dalam memilih
                default: 
                    cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto iya;
            }
        }
    }

    // Terdapat label langsungg sebagai tempat untuk melihat data ketika sudah tidak ingin menghapus data
    langsungg:
    lihatdata();
}


//prosedur algoritma bubble_sort secara ascending
void bubble_sort_Umur_Asc(anggota arr[])
{
	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 48; j++){
			if(arr[j].umur > arr[j+1].umur &&
			(arr[j].umur != 0 && arr[j+1].umur != 0))
            {
				swap(arr[j], arr[j+1]);
            }			
		}
	}
    //data umur berhasil disorting dengan menggunakan algoritma bubble sort 
    cout<<"bubble sort selesai !"<<endl; 
}


//prosedur algoritma bubble_sort secara descending
void bubble_sort_Umur_Desc(anggota arr[])
{
	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 48; j++){
			if(arr[j].umur < arr[j+1].umur &&
			(arr[j].umur != 0 && arr[j+1].umur != 0))
            {
				swap(arr[j], arr[j+1]);
            }			
		}
	}
    //data umur berhasil disorting dengan menggunakan algoritma bubble sort 
    cout<<"bubble sort selesai !"<<endl; 
}


//prosedur algoritma bubble_sort secara ascending
void bubble_sort_Raket_Asc(anggota arr[])
{
	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 48; j++){
			if(arr[j].ketersediaan > arr[j+1].ketersediaan &&
			(arr[j].ketersediaan != 0 && arr[j+1].ketersediaan != 0))
            {
				swap(arr[j], arr[j+1]);
            }			
		}
	}
    //data ketersediaan raket berhasil disorting dengan menggunakan algoritma bubble sort 
    cout<<"bubble sort selesai !"<<endl; 
}


//prosedur algoritma bubble_sort secara descending
void bubble_sort_Raket_Desc(anggota arr[])
{
	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 48; j++){
			if(arr[j].ketersediaan < arr[j+1].ketersediaan &&
			(arr[j].ketersediaan != 0 && arr[j+1].ketersediaan != 0))
            {
				swap(arr[j], arr[j+1]);
            }			
		}
	}
    //data ketersediaan raket berhasil disorting dengan menggunakan algoritma bubble sort 
    cout<<"bubble sort selesai !"<<endl; 
}


//prosedur algoritma selection_sort secara ascending
void selection_sort_Umur_Asc(anggota arr[], int n)
{
    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
        if (arr[j].umur < arr[min_index].umur && arr[min_index].umur != 0 && arr[j].umur != 0)
        {
            min_index = j;
            swap(arr[min_index], arr[i]);
        }
    }
    //data umur berhasil disorting dengan menggunakan algoritma selection sort
    cout<<"selection sort selesai !"<<endl;
}

//prosedur algoritma selection_sort secara descending
void selection_sort_Umur_Desc(anggota arr[], int n)
{
    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
        if (arr[j].umur > arr[min_index].umur && arr[min_index].umur != 0 && arr[j].umur != 0)
        {
            min_index = j;
            swap(arr[min_index], arr[i]);
        }
    }
    //data umur berhasil disorting dengan menggunakan algoritma selection sort
    cout<<"selection sort selesai !"<<endl;
}


//prosedur algoritma selection_sort secara ascending
void selection_sort_Raket_Asc(anggota arr[], int n)
{
    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
        if (arr[j].ketersediaan < arr[min_index].ketersediaan && arr[min_index].ketersediaan != 0 && arr[j].ketersediaan != 0)
        {
            min_index = j;
            swap(arr[min_index], arr[i]);
        }
    }
    //data umur berhasil disorting dengan menggunakan algoritma selection sort
    cout<<"selection sort selesai !"<<endl;
}


//prosedur algoritma selection_sort secara descending
void selection_sort_Raket_Desc(anggota arr[], int n)
{
    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
        if (arr[j].ketersediaan > arr[min_index].ketersediaan && arr[min_index].ketersediaan != 0 && arr[j].ketersediaan != 0)
        {
            min_index = j;
            swap(arr[min_index], arr[i]);
        }
    }
    //data umur berhasil disorting dengan menggunakan algoritma selection sort
    cout<<"selection sort selesai !"<<endl;
}


// prosedur algoritma insertion_sort secara ascending
void insertion_sort_Umur_Asc(anggota arr[], int n)
{
    for (i = 1; i < n; i++)
    {
        anggota key = arr[i];
        j = i-1;
        while (j <= 0 && arr[j].umur > key.umur)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    //data umur berhasil disorting dengan menggunakan algoritma insertion sort
    cout<<"insetion sort selesai!"<<endl; 
}


// prosedur algoritma insertion_sort secara descending
void insertion_sort_Umur_Desc(anggota arr[], int n)
{
    for (i = 1; i < n; i++)
    {
        anggota key = arr[i];
        j = i-1;
        while (j <= 0 && arr[j].umur < key.umur)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    //data umur berhasil disorting dengan menggunakan algoritma insertion sort
    cout<<"insetion sort selesai!"<<endl; 
}


// prosedur algoritma insertion_sort secara ascending
void insertion_sort_Raket_Asc(anggota arr[], int n)
{
    for (i = 1; i < n; i++)
    {
        anggota key = arr[i];
        j = i-1;
        while (j <= 0 && arr[j].ketersediaan > key.ketersediaan)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    //data ketersediaan raket berhasil disorting dengan menggunakan algoritma insertion sort
    cout<<"insetion sort selesai!"<<endl; 
}


// prosedur algoritma insertion_sort secara descending
void insertion_sort_Raket_Desc(anggota arr[], int n)
{
    for (i = 1; i < n; i++)
    {
        anggota key = arr[i];
        j = i-1;
        while (j <= 0 && arr[j].ketersediaan < key.ketersediaan)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    //data ketersediaan raket berhasil disorting dengan menggunakan algoritma insertion sort
    cout<<"insetion sort selesai!"<<endl; 
}


//prosedur untuk memilih urutan sorting secara ascending atau descending
void urutan()
{
    sorting:
    cout<<"\n==================================== SORTING DATA ANGGOTA ====================================";
    cout<<"\n================================== PILIHAN URUTAN SORTING ===================================\n";
    cout<<"1. Urutkan berdasarkan Ascending  : "<< endl;
    cout<<"2. Urutkan berdasarkan Descending : \n"<< endl;
    cout<<"0. Exit : "<< endl;
    urut = getch();
    switch(urut)
    {
        case '1':{system("cls");tampilan_sorting_Asc();break;}
        case '2':{system("cls");tampilan_sorting_Desc();break;}
        case '0':{break;}

        default:{cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto sorting;}
    }
}

//prosedur untuk tampilan sorting dengan urutan secara asceding
void tampilan_sorting_Asc()
{
    sortingg:
    cout<<"\n================================ SORTING DATA ANGGOTA ================================";
    cout<<"\n================================== PILIHAN SORTING ===================================\n";
    cout<<"1. Bubble Sort    (Mengurutkan umur anggota)"<< endl;
    cout<<"2. Insertion Sort (Mengurutkan umur anggota)"<< endl;   
    cout<<"3. Selection Sort (Mengurutkan umur anggota)\n"<< endl;
    cout<<"4. Bubble Sort    (Mengurutkan ketersediaan raket anggota)"<< endl;
    cout<<"5. Insertion Sort (Mengurutkan ketersediaan raket anggota)"<< endl;
    cout<<"6. Selection Sort (Mengurutkan ketersediaan raket anggota)\n"<< endl; 
    cout<<"0. Exit"<<endl;
    cout<<"Masukan Pilihan anda : ";
    pilih = getch();
    switch (pilih)
    {
        case'1':{system("cls");bubble_sort_Umur_Asc(data_anggota);goto sortingg;}
        case'2':{system("cls");insertion_sort_Umur_Asc(data_anggota, n);goto sortingg;}
        case'3':{system("cls");selection_sort_Umur_Asc(data_anggota, n);goto sortingg;}
        case'4':{system("cls");bubble_sort_Raket_Asc(data_anggota);goto sortingg;}
        case'5':{system("cls");insertion_sort_Raket_Asc(data_anggota, n);goto sortingg;}
        case'6':{system("cls");selection_sort_Raket_Asc(data_anggota, n);goto sortingg;}
        case'0':{break;}

        default:{cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto sortingg;}
    }
}


//prosedur untuk tampilan sorting dengan urutan secara desceding
void tampilan_sorting_Desc()
{
    sortingg:
    cout<<"\n================================ SORTING DATA ANGGOTA ================================";
    cout<<"\n================================== PILIHAN SORTING ===================================\n";
    cout<<"1. Bubble Sort    (Mengurutkan umur anggota)"<< endl;
    cout<<"2. Insertion Sort (Mengurutkan umur anggota)"<< endl;   
    cout<<"3. Selection Sort (Mengurutkan umur anggota)\n"<< endl;
    cout<<"4. Bubble Sort    (Mengurutkan ketersediaan raket anggota)"<< endl;
    cout<<"5. Insertion Sort (Mengurutkan ketersediaan raket anggota)"<< endl;
    cout<<"6. Selection Sort (Mengurutkan ketersediaan raket anggota)\n"<< endl; 
    cout<<"0. Exit"<<endl;
    cout<<"Masukan Pilihan anda : ";
    pilih = getch();
    switch (pilih)
    {
        case'1':{system("cls");bubble_sort_Umur_Desc(data_anggota);goto sortingg;}
        case'2':{system("cls");insertion_sort_Umur_Desc(data_anggota, n);goto sortingg;}
        case'3':{system("cls");selection_sort_Umur_Desc(data_anggota, n);goto sortingg;}
        case'4':{system("cls");bubble_sort_Raket_Desc(data_anggota);goto sortingg;}
        case'5':{system("cls");insertion_sort_Raket_Desc(data_anggota, n);goto sortingg;}
        case'6':{system("cls");selection_sort_Raket_Desc(data_anggota, n);goto sortingg;}
        case'0':{break;}

        default:{cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto sortingg;}
    }
}