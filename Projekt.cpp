
struct Data
{
    int rok;
    int miesiac;
    int dzien;
};
struct ObiektWypozyczenia
{
    int ID;
    char nazwa_obiektu[70];
    char imie_autora[20];
    char nazwisko_autora[40];
    char kategoria[15];
    struct Data wsk_na_date;
    char imie_wypozyczajacego[20];
    char nazwisko_wypozyczajacego[40];
    char inne_dane[30];
    struct ObiektWypozyczenia *next;
    struct ObiektWypozyczenia *prev;
};
struct ObiektWypozyczenia *head=NULL;
struct ObiektWypozyczenia *tail=NULL;

int unikalne_ID = 1;;

void FillObject(ObiektWypozyczenia *obiekt) // zrobienie by obiekty byly puste
{
    char tmp[70];
    struct Data data;
    obiekt->ID = 0;
    strcpy(obiekt->imie_autora,"");
    strcpy(obiekt->imie_wypozyczajacego,"");
    strcpy(obiekt->inne_dane,"");
    strcpy(obiekt->kategoria,"");
    strcpy(obiekt->nazwa_obiektu,"");
    strcpy(obiekt->nazwisko_autora,"");
    strcpy(obiekt->nazwisko_wypozyczajacego,"");
    obiekt->next=NULL;
    obiekt->prev=NULL;
    obiekt->wsk_na_date= data;
    return;
}

void RemoveEnter(char tmp[],int rozmiar) // zastepujemy enter, ktory wczytuje sie do tablicy przy funkcji fgets, pustym znakiem
{
    for(int i=0;i<rozmiar;i++)
    {
        if(tmp[i]=='\n')
            tmp[i]=0; //znak pusty
    }
    return;
}
void dodaj_obiekt()
{
    char tymczasowy_tytul[70];
    bool flaga = true;
    int wybor;
    if(head==NULL)
    {
        head = new ObiektWypozyczenia;
        head->ID = unikalne_ID;
        unikalne_ID++;
        head->next = NULL;
        head->prev = NULL;
        while(flaga)
        {
            printf("-------------------");
            printf("\nDostepne kategorie:\n1. Film\n2. Gra planszowa\n3. Ksiazka\n");
            printf("-------------------\n");
            printf("Wybierz kategorie, do ktorej nalezy przydzielic nowy obiekt: ");
            scanf("%d", &wybor);
            fflush(stdin);
            switch(wybor)
            {
                case 1:
                    strcpy(head->kategoria, "film");
                    printf("Podaj tytul filmu: ");
                    fgets(tymczasowy_tytul, 70, stdin);
                    flaga = false;
                    break;
                case 2:
                    strcpy(head->kategoria, "gra planszowa");
                    printf("Podaj tytul gry planszowej: ");
                    fgets(tymczasowy_tytul, 70, stdin);
                    flaga = false;
                    break;
           asd
        fflush(stdin);
        RemoveEnter(tymczasowy_tytul,20);
        strcpy(head->nazwa_obiektu, tymczasowy_tytul);

        printf(" Podaj imie autora: ");
        fgets(head->imie_autora, 20, stdin);
        RemoveEnter(head->imie_autora,20);

        printf(" Podaj nazwisko autora: ");
        fflush(stdin);
        fgets(head->nazwisko_autora, 40, stdin);
        RemoveEnter(head->nazwisko_autora,40);

        printf(" Pomyslnie dodano ten obiekt!\n");
        tail=head;
        strcpy(head->imie_wypozyczajacego, "");
        strcpy(head->nazwisko_wypozyczajacego,"");

    }
    else
    {
        struct ObiektWypozyczenia *wsk=head;
        while(wsk->next!=NULL)
        {
            wsk = wsk->next;
        }
        struct ObiektWypozyczenia *element = new ObiektWypozyczenia;
        wsk->next = element;
        element->prev = wsk;
        element->next = NULL;
        tail = element;
        element->ID = unikalne_ID;
        unikalne_ID++;
         while(flaga)
        {
            printf("-------------------");
            printf("\nDostepne kategorie:\n1. Film\n2. Gra planszowa\n3. Ksiazka\n");
            printf("-------------------\n");
            printf("Wybierz kategorie, do ktorej nalezy przydzielic nowy obiekt: ");
            fflush(stdin);
            scanf("%d", &wybor);
            switch(wybor)
            {
                case 1:
                    strcpy(element->kategoria, "film");
                    printf("Podaj tytul filmu: ");
                    fflush(stdin);
                    fgets(tymczasowy_tytul, 100, stdin);
                    flaga = false;
                    break;
                case 2:
                    strcpy(element->kategoria, "gra planszowa");
                    printf("Podaj tytul gry planszowej: ");
                    fflush(stdin);
                    fgets(tymczasowy_tytul, 100, stdin);
                    flaga = false;
                    break;
                case 3:
                    strcpy(element->kategoria, "ksiazka");
                    printf("Podaj tytul ksiazki: ");
                    fflush(stdin);
                    fgets(tymczasowy_tytul, 100, stdin);
                    flaga = false;
                    break;
                default:
                    printf("\nPodano nieistniejaca kategorie!\nSprobuj wybrac kategorie jeszcze raz.\n\n");
                    break;
            }
        }
        fflush(stdin);
        RemoveEnter(tymczasowy_tytul,20);
        strcpy(element->nazwa_obiektu, tymczasowy_tytul);

        printf("Podaj imie autora: ");
        fgets(element->imie_autora, 20, stdin);
        RemoveEnter(element->imie_autora,20);

        printf("Podaj nazwisko autora: ");
        fgets(element->nazwisko_autora, 40, stdin);
        RemoveEnter(element->nazwisko_autora,40);


        printf("\nPomyslnie dodano ten obiekt!\n");
        tail=element;
        strcpy(element->imie_wypozyczajacego, "");
        strcpy(element->nazwisko_wypozyczajacego,"");
    }
}
void usun_poprzez_ID()
{
    struct ObiektWypozyczenia *usun=head;
    int id_do_usuniecia;
    printf("Podaj ID obiektu do usuniecia: ");
    scanf("%d", &id_do_usuniecia);
    if(head->ID==id_do_usuniecia)
    {
        if(head->next==NULL)
        {
            delete usun;
            head=NULL;
            printf("Pomyslnie usunieto ten obiekt!\n");
            return;
        }
        head = usun->next;
        head->prev=NULL;
        delete usun;
        printf("Pomyslnie usunieto ten obiekt!\n");
        return;
    }
    while(usun!=NULL)
    {
        if(usun->ID==id_do_usuniecia && usun==tail)
        {
            tail=usun->prev;
            tail->next=NULL;
            delete usun;
            printf("Pomyslnie usunieto ten obiekt!\n");
            return;
        }
        if(usun->ID==id_do_usuniecia)
        {
            struct ObiektWypozyczenia *poprzednik = usun->prev;
            struct ObiektWypozyczenia *nastepnik = usun->next;
            poprzednik->next = nastepnik;
            nastepnik->prev = poprzednik;
            delete usun;
            printf("Pomyslnie usunieto ten obiekt!\n");
            return;
        }
        usun = usun->next;
    }
    printf("Nie ma obiektu o takim ID!\nUsuwanie nie powiodlo sie...\n");
    return;
}
void usun_poprzez_nazwe()
{
    struct ObiektWypozyczenia *usun=head;
    char nazwa_do_usuniecia[70];
    printf("Podaj tytul (nazwe) obiektu do usuniecia: ");
    fflush(stdin);
    fgets(nazwa_do_usuniecia, 70, stdin);
    RemoveEnter(nazwa_do_usuniecia, 70);                                   // trzeba dac przy wyszukiwaniu po stringu by enterow nie bylo
    fflush(stdin);
    int porownanie_head = strcmp(nazwa_do_usuniecia, head->nazwa_obiektu);
    if(porownanie_head==0)
    {
        if(head->next==NULL)
        {
            delete usun;
            head=NULL;
            printf("Pomyslnie usunieto ten obiekt!\n");
            return;
        }
        head = usun->next;
        head->prev=NULL;
        delete usun;
        printf("Pomyslnie usunieto ten obiekt!\n");
        return;
    }
    while(usun!=NULL)
    {
        int porownanie_nazw = strcmp(nazwa_do_usuniecia, usun->nazwa_obiektu);
        if(porownanie_nazw == 0 && usun==tail)
        {
            tail=usun->prev;
            tail->next=NULL;
            delete usun;
            printf("Pomyslnie usunieto ten obiekt!\n");
            return;
        }
        if(porownanie_nazw == 0)
        {
            struct ObiektWypozyczenia *poprzednik = usun->prev;
            struct ObiektWypozyczenia *nastepnik = usun->next;
            poprzednik->next = nastepnik;
            nastepnik->prev = poprzednik;
            delete usun;
            printf("Pomyslnie usunieto ten obiekt!\n");
            return;
        }
        usun = usun->next;
    }
    printf("Nie ma obiektu o takim tytule!\nUsuwanie nie powiodlo sie...\n");
    return;
}
void usun_obiekt()
{
    if(head==NULL)
    {
        printf("Opcja usuwania nie dziala, gdyz lista jest pusta!\n");
        return;
    }
    bool flaga = true;
    int opcja;
    while(flaga)
    {
        printf("------------------------------------------------------\n");
        printf("Dostepne opcje usuwania:\n1. Poprzez podanie ID obiektu do usuniecia\n2. Poprzez podanie tytulu (nazwy) obiektu do usuniecia\n3. Nie chce nic ususwac\n");
        printf("------------------------------------------------------\n");
        printf("Wybierz sposob: ");
        scanf("%d", &opcja);
        switch(opcja)
        {
            case 1:
                usun_poprzez_ID();
                flaga = false;
                break;
            case 2:
                usun_poprzez_nazwe();
                flaga = false;
                break;
            case 3:
                flaga = false;
                break;
            default:
                printf("\nWybrana opcja jest niedostepna.\nSprobuj ponownie!\n\n");
                break;
        }
    }
}
void edytuj_wybor_ID()
{
    bool flaga = true;
    char wybor[2] = {};
    int szukane_ID;
    printf("Podaj ID: ");
    scanf("%d", &szukane_ID);
    struct ObiektWypozyczenia *wsk=head;
    while(wsk!=NULL)
    {
        if( wsk->ID == szukane_ID)
        {
                while(flaga)
                {
                    printf("-------------------");
                    printf("\nDostepne kategorie:\n1. Film\n2. Gra planszowa\n3. Ksiazka\n");
                    printf("-------------------\n");
                    printf("Wybierz kategorie, do ktorej nalezy przydzielic edytowany obiekt: ");
                    fflush(stdin);
                    fgets(wybor,2,stdin);
                    if(wybor[0] == '\n')
                        break;
                    switch(wybor[0])
                    {
                        case '1':
                            strcpy(wsk->kategoria, "film");
                            flaga = false;
                            break;
                        case '2':
                            strcpy(wsk->kategoria, "gra planszowa");
                            flaga = false;
                            break;
                        case '3':
                            strcpy(wsk->kategoria, "ksiazka");
                            flaga = false;
                            break;
                        default:
                            printf("\nPodano nieistniejaca kategorie!\nSprobuj wybrac kategorie jeszcze raz.\n\n");
                            break;
                    }
                }
                char authorName[20] = {}, authorLastname[40]={},title[70] ={};

                printf("Podaj tytul: ");
                fflush(stdin);
                fgets(title, 70, stdin);
                if(title[0] != 10)
                {
                    RemoveEnter(title, 70);
                    {strncpy(wsk->nazwa_obiektu, title,70);}
                }
                printf("Podaj imie autora: ");
                fflush(stdin);
                fgets(authorName, 20, stdin);
                if(authorName[0] != '\n')
                {
                    RemoveEnter(authorName, 20);
                    {strncpy(wsk->imie_autora,authorName,20);}
                }
                printf("Podaj nazwisko autora: ");
                fflush(stdin);
                fgets(authorLastname, 40, stdin);
                if(authorLastname[0] != '\n')
                {
                    RemoveEnter(authorLastname, 40);
                    {strncpy(wsk->nazwisko_autora,authorLastname,40);}
                }
                fflush(stdin);
                printf("\nPomyslnie edytowano ten obiekt!\n");
                return;

        }
        wsk = wsk->next;
    }
    printf("Nie ma obiektu o takim ID!\nNie dojdzie do edycji danych\n");
    return;

}
void edytuj_wybor_nazwy()
{
    int porownanie_nazw;
    char szukany_tytul[70];
    bool flaga = true;
    char wybor[2] = {};
    printf("Podaj tytul szukanego obiektu: ");
    fflush(stdin);
    fgets(szukany_tytul, 70, stdin);
    RemoveEnter(szukany_tytul, 70);
    fflush(stdin);
    struct ObiektWypozyczenia *wsk=head;
    while(wsk!=NULL)
    {
        porownanie_nazw = strcmp(szukany_tytul, wsk->nazwa_obiektu);
        if(porownanie_nazw == 0)
        {
            while(flaga)
            {
                printf("-------------------");
                printf("\nDostepne kategorie:\n1. Film\n2. Gra planszowa\n3. Ksiazka\n");
                printf("-------------------\n");
                printf("Wybierz kategorie, do ktorej nalezy przydzielic edytowany obiekt: ");
                fflush(stdin);
                fgets(wybor, 2, stdin);
                if(wybor[0] == '\n')
                    break;
                switch(wybor[0])
                {
                    case '1':
                        strcpy(wsk->kategoria, "film");
                        flaga = false;
                        break;
                    case '2':
                        strcpy(wsk->kategoria, "gra planszowa");
                        break;
                    case '3':
                        strcpy(wsk->kategoria, "ksiazka");
                        flaga = false;
                        break;
                    default:
                        printf("\nPodano nieistniejaca kategorie!\nSprobuj wybrac kategorie jeszcze raz.\n\n");
                        break;
                }
            }
                char authorName[20] = {}, authorLastname[40]={},title[70] ={};

                printf("Podaj tytul: ");
                fflush(stdin);
                fgets(title, 70, stdin);
                 if(title[0] != 10)
                {
                    RemoveEnter(title, 70);
                    {strncpy(wsk->nazwa_obiektu, title,70);}
                }
                printf("Podaj imie autora: ");
                fflush(stdin);
                fgets(authorName, 20, stdin);
                if(authorName[0] != '\n')
                {
                    RemoveEnter(authorName, 20);
                    {strncpy(wsk->imie_autora,authorName,20);}
                }
                printf("Podaj nazwisko autora: ");
                fflush(stdin);
                fgets(authorLastname, 40, stdin);
                if(authorLastname[0] != '\n')
                {
                    RemoveEnter(authorLastname, 40);
                    {strncpy(wsk->nazwisko_autora,authorLastname,40);}
                }
                fflush(stdin);
                printf("\nPomyslnie edytowano ten obiekt!\n");
                return;
        }
        wsk = wsk->next;
    }
    printf("Nie ma obiektu o takim tytule!\nNie dojdzie do edycji danych\n");
    return;
}
void edytuj_dane_obiektu()
{
    if(head==NULL)
    {
        printf("Opcja edytowania nie dziala, gdyz lista jest pusta!\n");
        return;
    }
    bool flaga = true;
    int opcja;
    while(flaga)
    {
        printf("------------------------------------------------------\n");
        printf("Dostepne opcje wyboru obiektu do edytowania jego danych:\n1. Poprzez podanie ID obiektu do edytowania\n2. Poprzez podanie tytulu (nazwy) obiektu do edytowania\n3. Nie chce nic edytowac\n");
        printf("------------------------------------------------------\n");
        printf("Wybierz sposob: ");
        scanf("%d", &opcja);
        switch(opcja)
        {
            case 1:
                edytuj_wybor_ID();
                flaga = false;
                break;
            case 2:
                edytuj_wybor_nazwy();
                flaga = false;
                break;
            case 3:
                flaga = false;
                break;
            default:
                printf("\nWybrana opcja jest niedostepna.\nSprobuj ponownie!\n\n");
                break;
        }
    }
}
void zmien_status_obiektu_ID()
{
    char imie[20];
    char nazwisko[40];
    strcpy(imie, "");
    strcpy(nazwisko, "");
    int szukane_id;
    int opcja;
    printf("Podaj ID obiektu: ");
    scanf("%d", &szukane_id);
    struct ObiektWypozyczenia *wsk=head;
    while(wsk!=NULL)
    {
        if(wsk->ID==szukane_id)
        {
            int porownanie = strcmp(wsk->nazwisko_wypozyczajacego, nazwisko);
            if(porownanie == 0)
            {
                printf("\nObiekt jest dostepny do wypozyczenia.\n\n");
                printf("Wprowadz dane osoby wypozyczajacej:\n");
                printf("Imie: ");
                fflush(stdin);
                fgets(wsk->imie_wypozyczajacego, 20, stdin);
                RemoveEnter(wsk->imie_wypozyczajacego, 20);
                printf("Nazwisko: ");
                fflush(stdin);
                fgets(wsk->nazwisko_wypozyczajacego, 40, stdin);
                RemoveEnter(wsk->nazwisko_wypozyczajacego, 40);
                printf("\nWprowadz date wypozyczenia:\n->przykladowa data: 02 01 2022<-\n");
                printf("Dzien: ");
                scanf("%d", &wsk->wsk_na_date.dzien);
                if(wsk->wsk_na_date.dzien<=0 || wsk->wsk_na_date.dzien>31)
                {
                    do
                    {
                        printf("\nPodano blednie dzien!\nProsze sprobowac ponownie:\n\nDzien: ");
                        scanf("%d", &wsk->wsk_na_date.dzien);
                    }while(wsk->wsk_na_date.dzien<=0 || wsk->wsk_na_date.dzien>31);
                }
                printf("Miesiac: ");
                scanf("%d", &wsk->wsk_na_date.miesiac);
                if(wsk->wsk_na_date.miesiac<=0 || wsk->wsk_na_date.miesiac>12)
                {
                    do
                    {
                        printf("\nPodano blednie miesiac!\nProsze sprobowac ponownie:\n\nMiesiac: ");
                        scanf("%d", &wsk->wsk_na_date.miesiac);
                    }while(wsk->wsk_na_date.miesiac<=0 || wsk->wsk_na_date.miesiac>12);
                }
                printf("Rok: ");
                scanf("%d", &wsk->wsk_na_date.rok);
                if(wsk->wsk_na_date.rok<2022 || wsk->wsk_na_date.rok>2100)
                {
                    do
                    {
                        printf("\nPodano nie aktualny rok!\nProsze sprobowac ponownie:\n\nRok: ");
                        scanf("%d", &wsk->wsk_na_date.rok);
                    }while(wsk->wsk_na_date.rok<2022 || wsk->wsk_na_date.rok>2100);
                }
                printf("\nPomyslnie zapisano zmiany!\nObiekt zostal wypozyczony!\n");
                return;
            }
            else
            {
                printf("\n");
                printf("%s: %s", wsk->kategoria, wsk->nazwa_obiektu);
                printf("\nimie autora: %s", wsk->imie_autora);
                printf("\nnazwisko autora: %s",wsk->nazwisko_autora);
                printf("\n- jest obecnie wypozyczone przez -\n");
                printf("imie wypozyczajacego: %s",wsk->imie_wypozyczajacego);
                printf("\nnazwisko wypozyczajacego: %s",wsk->nazwisko_wypozyczajacego);
                printf("\nData wypozyczenia: %d %d %d",wsk->wsk_na_date.dzien,wsk->wsk_na_date.miesiac, wsk->wsk_na_date.rok);
                printf("\n\nCzy zmienic status obiektu na oddany?\n1. Tak\n2. Nie\nWybierz opcje: ");
                scanf("%d", &opcja);
                if(opcja==1)
                {
                    strcpy(wsk->imie_wypozyczajacego, imie);
                    strcpy(wsk->nazwisko_wypozyczajacego, nazwisko);
                    wsk->wsk_na_date.dzien=NULL;
                    wsk->wsk_na_date.miesiac=NULL;
                    wsk->wsk_na_date.rok=NULL;
                    printf("\nPomyslnie zmieniono status obiektu na oddany!\n");
                    return;
                }
                else
                {
                    printf("Powrot do glownego menu...\n");
                    return;
                }
            }

        }
        wsk = wsk->next;
    }
    printf("Nie ma obiektu o takim ID,\ndlatego nie dojdzie do zmiany statusu obiektu!\n");
    return;

}
void zmien_status_obiektu_tytul()
{
    int spr_tytul;
    char szukany_tytul[70];
    char imie[20];
    char nazwisko[40];
    strcpy(imie, "");
    strcpy(nazwisko, "");
    int opcja;
    printf("Podaj tytul (nazwe) obiektu: ");
    fflush(stdin);
    fgets(szukany_tytul, 70, stdin);
    RemoveEnter(szukany_tytul, 70);
    struct ObiektWypozyczenia *wsk=head;
    while(wsk!=NULL)
    {
        spr_tytul = strcmp(szukany_tytul, wsk->nazwa_obiektu);
        if(spr_tytul == 0)
        {
            int porownanie = strcmp(wsk->nazwisko_wypozyczajacego, nazwisko);
            if(porownanie == 0)
            {
                printf("\nObiekt jest dostepny do wypozyczenia.\n\n");
                printf("Wprowadz dane osoby wypozyczajacej:\n");
                printf("Imie: ");
                fflush(stdin);
                fgets(wsk->imie_wypozyczajacego, 20, stdin);
                RemoveEnter(wsk->imie_wypozyczajacego, 20);
                printf("Nazwisko: ");
                fflush(stdin);
                fgets(wsk->nazwisko_wypozyczajacego, 40, stdin);
                RemoveEnter(wsk->nazwisko_wypozyczajacego, 40);
                printf("\nWprowadz date wypozyczenia:\n->przykladowa data: 02 01 2022<-\n");
                printf("Dzien: ");
                scanf("%d", &wsk->wsk_na_date.dzien);
                if(wsk->wsk_na_date.dzien<=0 || wsk->wsk_na_date.dzien>31)
                {
                    do
                    {
                        printf("\nPodano blednie dzien!\nProsze sprobowac ponownie:\n\nDzien: ");
                        scanf("%d", &wsk->wsk_na_date.dzien);
                    }while(wsk->wsk_na_date.dzien<=0 || wsk->wsk_na_date.dzien>31);
                }
                printf("Miesiac: ");
                scanf("%d", &wsk->wsk_na_date.miesiac);
                if(wsk->wsk_na_date.miesiac<=0 || wsk->wsk_na_date.miesiac>12)
                {
                    do
                    {
                        printf("\nPodano blednie miesiac!\nProsze sprobowac ponownie:\n\nMiesiac: ");
                        scanf("%d", &wsk->wsk_na_date.miesiac);
                    }while(wsk->wsk_na_date.miesiac<=0 || wsk->wsk_na_date.miesiac>12);
                }
                printf("Rok: ");
                scanf("%d", &wsk->wsk_na_date.rok);
                if(wsk->wsk_na_date.rok<2022 || wsk->wsk_na_date.rok>2100)
                {
                    do
                    {
                        printf("\nPodano nie aktualny rok!\nProsze sprobowac ponownie:\n\nRok: ");
                        scanf("%d", &wsk->wsk_na_date.rok);
                    }while(wsk->wsk_na_date.rok<2022 || wsk->wsk_na_date.rok>2100);
                }
                printf("\n\nPomyslnie zapisano zmiany!\nObiekt zostal wypozyczony!\n");
                return;
            }
            else
            {
                printf("\n");
                printf("%s: %s", wsk->kategoria, wsk->nazwa_obiektu);
                printf("\nimie autora: %s", wsk->imie_autora);
                printf("\nnazwisko autora: %s",wsk->nazwisko_autora);
                printf("\n- jest obecnie wypozyczone przez -\n");
                printf("imie wypozyczajacego: %s",wsk->imie_wypozyczajacego);
                printf("\nnazwisko wypozyczajacego: %s",wsk->nazwisko_wypozyczajacego);
                printf("\nData wypozyczenia: %d %d %d",wsk->wsk_na_date.dzien,wsk->wsk_na_date.miesiac, wsk->wsk_na_date.rok);
                printf("\n\nCzy zmienic status obiektu na oddany?\n1. Tak\n2. Nie\nWybierz opcje: ");
                scanf("%d", &opcja);
                if(opcja==1)
                {
                    strcpy(wsk->imie_wypozyczajacego, imie);
                    strcpy(wsk->nazwisko_wypozyczajacego, nazwisko);
                    wsk->wsk_na_date.dzien=NULL;
                    wsk->wsk_na_date.miesiac=NULL;
                    wsk->wsk_na_date.rok=NULL;
                    printf("\nPomyslnie zmieniono status obiektu na oddany!\n");
                    return;
                }
                else
                {
                    printf("Powrot do glownego menu...\n");
                    return;
                }
            }

        }
        wsk = wsk->next;
    }
    printf("\nNie ma obiektu o takim tytule,\ndlatego nie dojdzie do zmiany statusu obiektu!\n\n");
    return;
}
void zmien_status_obiektu()
{
    if(head==NULL)
    {
        printf("Opcja chwilowo niedostepna, gdyz lista jest pusta.\n");
        return;
    }
    bool flaga = true;
    int wybor;
    while(flaga)
    {
        printf("\nDostepne opcje wyboru obiektu do zmiany jego statusu:\n\n1. poprzez podanie tytulu obiektu (jego nazwy)\n2. poprzez podanie ID obiektu\n3. rezygnuje ze zmiany statusu obiektu...\nWybierz opcje: ");
        scanf("%d", &wybor);
        switch(wybor)
        {
            case 1:
                zmien_status_obiektu_tytul();
                flaga = false;
                break;
            case 2:
                zmien_status_obiektu_ID();
                flaga = false;
                break;
            case 3:
                printf("Powrot do menu glownego...\n");
                flaga = false;
                break;
            default:
                printf("\nNie ma dostepnej takiej opcji!\nSprobuj ponownie.\n");
                break;
        }
    }
}
void wyszukaj_po_ID()
{
    char nazwisko[40];
    strcpy(nazwisko, "");
    int porownanie_nazwisk;
    int szukane_id;
    printf("Podaj ID: ");
    scanf("%d", &szukane_id);
    struct ObiektWypozyczenia *wsk=head;
    while(wsk!=NULL)
    {
        if(wsk->ID==szukane_id)
        {
            printf("\n");
            printf("ID: %d\n", wsk->ID);
            printf("Kategoria: %s",wsk->kategoria);
            printf("\nTytul: %s", wsk->nazwa_obiektu);
            printf("\nImie autora: %s", wsk->imie_autora);
            printf("\nNazwisko autora: %s\n", wsk->nazwisko_autora);
            porownanie_nazwisk = strcmp(wsk->nazwisko_wypozyczajacego, nazwisko);
            if(porownanie_nazwisk != 0)
            {
                printf("Imie wypozyczajacego: %s", wsk->imie_wypozyczajacego);
                printf("\nNazwisko wypozyczajacego: %s",wsk->nazwisko_wypozyczajacego);
                printf("\nData wypozyczenia: %d %d %d\n", wsk->wsk_na_date.dzien, wsk->wsk_na_date.miesiac, wsk->wsk_na_date.rok);
            }
            return;
        }
        wsk = wsk->next;
    }
    printf("Nie ma obiektu o takim ID!\n");
}
void wyszukaj_po_tytule()
{
    char nazwisko[40];
    strcpy(nazwisko, "");
    int porownanie_nazwisk;
    char tytul[70];
    struct ObiektWypozyczenia *wsk=head;
    printf("Podaj tytul obiektu: ");
    fflush(stdin);
    fgets(tytul, 70, stdin);
    RemoveEnter(tytul, 70);
    fflush(stdin);
    while(wsk!=NULL)
    {
        int porownanie_nazw = strcmp(wsk->nazwa_obiektu, tytul);
        if(porownanie_nazw == 0)
        {
            printf("\n");
            printf("ID: %d\n", wsk->ID);
            printf("Kategoria: %s",wsk->kategoria);
            printf("\nTytul: %s", wsk->nazwa_obiektu);
            printf("\nImie autora: %s", wsk->imie_autora);
            printf("\nNazwisko autora: %s\n", wsk->nazwisko_autora);
            porownanie_nazwisk = strcmp(wsk->nazwisko_wypozyczajacego, nazwisko);
            if(porownanie_nazwisk != 0)
            {
                printf("\nImie wypozyczajacego: %s", wsk->imie_wypozyczajacego);
                printf("\nNazwisko wypozyczajacego: %s",wsk->nazwisko_wypozyczajacego);
                printf("\nData wypozyczenia: %d %d %d\n", wsk->wsk_na_date.dzien, wsk->wsk_na_date.miesiac, wsk->wsk_na_date.rok);
            }
            return;
        }
        wsk = wsk->next;
    }
    printf("Nie ma obiektu o takim tytule!\n");
}
void wyszukaj_po_nazwisku_wypoz()
{
    struct ObiektWypozyczenia *wsk=head;
    char nazwisko[40];
    printf("Podaj nazwisko osoby wypozyczajecej: ");
    fflush(stdin);
    fgets(nazwisko, 40, stdin);
    RemoveEnter(nazwisko, 40);
    printf("Obiekty wypozyczone:\n");
    while(wsk!=NULL)
    {
        int porownanie_nazwisk = strcmp(wsk->nazwisko_wypozyczajacego, nazwisko);
        if(porownanie_nazwisk == 0)
        {
            printf("-----------------------------------------------------------\n");
            printf("ID: %d\n", wsk->ID);
            printf("Kategoria: %s",wsk->kategoria);
            printf("\nTytul: %s", wsk->nazwa_obiektu);
            printf("\nImie autora: %s", wsk->imie_autora);
            printf("\nNazwisko autora: %s", wsk->nazwisko_autora);
            printf("\nImie wypozyczajacego: %s", wsk->imie_wypozyczajacego);
            printf("\nNazwisko wypozyczajacego: %s",wsk->nazwisko_wypozyczajacego);
            printf("\nData wypozyczenia: %d %d %d\n", wsk->wsk_na_date.dzien, wsk->wsk_na_date.miesiac, wsk->wsk_na_date.rok);

            if(wsk->next==NULL)
            {
                printf("-----------------------------------------------------------\n");
                return;
            }
        }
        wsk = wsk->next;
    }
    printf("brak takich obiektow\n");
    return;
}
void wyszukaj_obiekt()
{
    bool flaga = true;
    if(head==NULL)
    {
        printf("Opcja nie dziala, gdyz lista jest pusta!\n");
        return;
    }
    int opcja;
    while(flaga)
    {
        printf("---------------------------------------\n");
        printf("Wybierz sposob wyszukania obiektu:\n1. Wyszukaj po ID\n2. Wyszukaj po tytule (nazwie)\n3. Wyszukaj po nazwisku wypozyczajacego\n4. Rezygnuje z wyszukiwania\n");
        printf("---------------------------------------\n");
        printf("Wybierz opcje: ");
        scanf("%d", &opcja);
        switch(opcja)
        {
        case 1:
            wyszukaj_po_ID();
            flaga = false;
            break;
        case 2:
            wyszukaj_po_tytule();
            flaga = false;
            break;
        case 3:
            wyszukaj_po_nazwisku_wypoz();
            flaga = false;
            break;
        case 4:
            printf("Powrot do glownego menu!\n");
            flaga = false;
            break;
        default:
            printf("Podano nieistniejacy numer opcji!\nSprobuj ponownie!\n");
            flaga = true;
            break;
        }


    }
}
void wyswietl_baze_po_nazwach()
{
    if(head==NULL)
    {
        printf("Baza jest pusta!\n");
        return;
    }
    else
    {
        struct ObiektWypozyczenia *wsk=head;
        while(wsk!=NULL)
        {
            printf("\nKategoria: %s",wsk->kategoria);
            printf("\nTytul: %s",wsk->nazwa_obiektu);
            printf("\nImie autora: %s", wsk->imie_autora);
            printf("\nNazwisko autora: %s", wsk->nazwisko_autora);
            printf("\nID: %d ", wsk->ID);
            printf("\n");
            wsk = wsk->next;
        }
    }
}
void wyswietl_obiekty_wypozyczone()
{
    int porownanie_nazwisk;
    int licznik = 0;
    if(head==NULL)
    {
        printf("Ta opcja jest na razie niedostepna, gdyz lista jest pusta!\n");
        return;
    }
    printf("\nObiekty wypozyczone:\n");
    struct ObiektWypozyczenia *wsk=head;
    while(wsk!=NULL)
    {
        porownanie_nazwisk = strcmp("", wsk->nazwisko_wypozyczajacego);
        if(porownanie_nazwisk != 0)
        {
            printf("------------------------------------------------\n");
            printf("->%s: %s", wsk->kategoria, wsk->nazwa_obiektu);
            printf("\n->imie osoby wypozyczajacej: %s",wsk->imie_wypozyczajacego);
            printf("\n->nazwisko osoby wypozyczajacej: %s\n",wsk->nazwisko_wypozyczajacego);
            licznik++;
        }
        wsk = wsk->next;
    }
    if(licznik==0)
    {
        printf("Brak wypozyczonych obiektow.\n");
        return;
    }
    else
    {
        printf("------------------------------------------------\n");
        printf("Laczna ilosc wypozyczonych obiektow: %d\n", licznik);
        return;
    }
}
void zapisz_do_pliku()
{
    if(head==NULL)
    {
        printf("Lista jest pusta,\nwiec nie mozna na razie zapisywac zawartosci listy do pliku!\n");
        return;
    }
    char nazwisko_wypozyczajacego[40];
    strcpy(nazwisko_wypozyczajacego, "");
    int porownanie_nazwisk;
    char nazwa_pliku[40];
    printf("Podaj nazwe pliku: ");
    scanf("%s", &nazwa_pliku);
    fflush(stdin);
    FILE *fp = fopen(nazwa_pliku, "w");
    if(fp==NULL)
    {
        printf("Blad otwierania pliku!\n");
        return;
    }
    struct ObiektWypozyczenia *wsk=head;
    while(wsk!=NULL)
    {
        fprintf(fp, "---------------------------------\n");
        fprintf(fp, "ID: %d\n", wsk->ID);
        fprintf(fp, "\nKategoria: %s\n", wsk->kategoria);
        fprintf(fp, "\nTytul: %s\n", wsk->nazwa_obiektu);
        fprintf(fp, "Imie autora: %s\n", wsk->imie_autora);
        fprintf(fp, "Nazwisko autora: %s\n", wsk->nazwisko_autora);
        porownanie_nazwisk = strcmp(nazwisko_wypozyczajacego, wsk->nazwisko_wypozyczajacego);
        if(porownanie_nazwisk!=0)
        {
            fprintf(fp, "Imie wypozyczajacego: %s\n", wsk->imie_wypozyczajacego);
            fprintf(fp, "Nazwisko wypozyczajacego: %s\n", wsk->nazwisko_wypozyczajacego);
            fprintf(fp, "Wypozyczone od: %d %d %d\n", wsk->wsk_na_date.dzien, wsk->wsk_na_date.miesiac, wsk->wsk_na_date.rok);
        }
        if(wsk->next==NULL)
        {
            fprintf(fp, "---------------------------------\n");
        }
        wsk=wsk->next;
    }
    fclose(fp);
    printf("Pomyslnie zapisano!\n");
}
void Czyszczenie_kolejki()
{
    struct ObiektWypozyczenia *wsk=head;
    if(head->next==NULL)
    {
        delete wsk;
        head=NULL;
        tail=NULL;
        return;
    }
    struct ObiektWypozyczenia *element_do_usuniecia=head;
    while(wsk!=NULL)
    {
        wsk=wsk->next;
        delete element_do_usuniecia;
        element_do_usuniecia=wsk;
    }
    delete wsk;
    delete element_do_usuniecia;
    head=NULL;
    tail=NULL;
}
void parsowanie(char linijka_tekstu[], char nazwa_zmiennej[], char wartosc_zmiennej[])
{
    int wartosc=0;
    int licznik=0;
    int nowa_iteracja=0;
    for(int i=0; i<128;i++)
    {
        if(linijka_tekstu[i]=='\n')
            break;
        if(licznik==0)
        {
            if(linijka_tekstu[i] == ':')
            {
                licznik=1;
                continue;
            }
            else
            {
                nazwa_zmiennej[i]=linijka_tekstu[i];
            }
        }
        if(licznik==1)
        {
            if(wartosc==0 && linijka_tekstu[i]==' ')
                continue;
            wartosc_zmiennej[wartosc]=linijka_tekstu[i];
            wartosc++;
        }

    }
}
void wypelnianie_obiektu(ObiektWypozyczenia *obiekt)
{
    struct Data data;
    obiekt->ID = 0;
    strcpy(obiekt->imie_autora,"");
    strcpy(obiekt->imie_wypozyczajacego,"");
    strcpy(obiekt->inne_dane,"");
    strcpy(obiekt->kategoria,"");
    strcpy(obiekt->nazwa_obiektu,"");
    strcpy(obiekt->nazwisko_autora,"");
    strcpy(obiekt->nazwisko_wypozyczajacego,"");
    obiekt->next=NULL;
    obiekt->prev=NULL;
    obiekt->wsk_na_date= data;
    return;
}
void odczytaj_z_pliku()
{
    char nazwa_pliku[40];
    fflush(stdin);
    printf("Podaj nazwe pliku: ");
    scanf("%s", &nazwa_pliku);

    FILE *file;
    file = fopen(nazwa_pliku, "r");
    if(file==NULL)
    {
        printf("Plik jest pusty!\n");
        return;
    }
    if(head!=NULL)
        Czyszczenie_kolejki();

    if(file)
    {
        char linijka_tekstu[128];
        struct ObiektWypozyczenia *obiekt=NULL;
        struct ObiektWypozyczenia *obiekt_nastepny=NULL;
        while(fgets(linijka_tekstu,sizeof(linijka_tekstu),file))
        {
            char nazwa_zmiennej[40]={};
            char wartosc_zmiennej[100]={};
            if(linijka_tekstu[0]=='\n')
                continue;
            parsowanie(linijka_tekstu, nazwa_zmiennej,wartosc_zmiennej);
            printf("%s\n", linijka_tekstu);

            if(strcmp(nazwa_zmiennej,"ID")==0)
            {
                if(obiekt==NULL)
                {
                    obiekt = new ObiektWypozyczenia;
                    wypelnianie_obiektu(obiekt);
                    head=obiekt;
                    tail=obiekt;
                }
                else
                {
                    obiekt_nastepny = new ObiektWypozyczenia;
                    wypelnianie_obiektu(obiekt_nastepny);
                    obiekt_nastepny->prev=obiekt;
                    obiekt->next=obiekt_nastepny;
                    obiekt=obiekt_nastepny;
                    tail=obiekt;
                }
                int id;
                sscanf(wartosc_zmiennej,"%d", &id);
                unikalne_ID=id+1;
                obiekt->ID=id;
            }
            if(strcmp(nazwa_zmiennej,"Kategoria")==0)
            {
                strncpy(obiekt->kategoria,wartosc_zmiennej,15);
            }
            if(strcmp(nazwa_zmiennej,"Tytul")==0)
            {
                strncpy(obiekt->nazwa_obiektu,wartosc_zmiennej,70);
            }
            if(strcmp(nazwa_zmiennej,"Imie autora")==0)
            {
                strncpy(obiekt->imie_autora,wartosc_zmiennej,20);
            }
            if(strcmp(nazwa_zmiennej,"Nazwisko autora")==0)
            {
                strncpy(obiekt->nazwisko_autora,wartosc_zmiennej,40);
            }
            if(strcmp(nazwa_zmiennej,"Imie wypozyczajacego")==0)
            {
                strncpy(obiekt->imie_wypozyczajacego,wartosc_zmiennej,20);
            }
            if(strcmp(nazwa_zmiennej,"Nazwisko wypozyczajacego")==0)
            {
                strncpy(obiekt->nazwisko_wypozyczajacego,wartosc_zmiennej,40);
            }
            if(strcmp(nazwa_zmiennej,"Wypozyczone od")==0)
            {
                int iteracja=0;
                int licznik_spacji=0;
                struct Data data;
                char tablica[20]={};
                for(int i=0;i<128;i++)
                {
                     if(wartosc_zmiennej[i] == '\n')
                        break;
                    if(wartosc_zmiennej[i]==' ')
                    {
                        if(licznik_spacji==0)
                        {
                            sscanf(tablica,"%d",&data.dzien);
                        }
                        if(licznik_spacji==1)
                        {
                            sscanf(tablica,"%d",&data.miesiac);
                        }
                        if(licznik_spacji==2)
                        {
                            sscanf(tablica,"%d",&data.rok);
                        }
                            memset(tablica,0,20);
                            iteracja=0;
                            licznik_spacji++;
                    }

                    if(wartosc_zmiennej[i]!=' ')
                        tablica[iteracja]=wartosc_zmiennej[i];
                }
                obiekt->wsk_na_date = data;
            }
        }
    }
    fclose(file);
}
void wielokrotne_dodawanie()
{
    int opcja;
    bool flaga = true;
    while(flaga)
    {
        dodaj_obiekt();
        printf("\nCzy chcesz dodac kolejny element?\n1. Tak, chce dodac kolejny element\n2. Nie, chce wrocic do glownego menu\nWybierz opcje: ");
        scanf("%d", &opcja);
        if(opcja==1) flaga = true;
        if(opcja==2) flaga = false;
        if(opcja != 1 && opcja != 2)
        {
            do
            {
                printf("\nNie ma takiej opcji!\nSprobuj jeszcze raz.\n");
                printf("\nCzy chcesz dodac kolejny element?\n1. Tak, chce dodac kolejny element\n2. Nie, chce wrocic do glownego menu\nWybierz opcje: ");
                scanf("%d", &opcja);
                if(opcja==2)
                {
                    flaga = false;
                    return;
                }
            }while(opcja != 1);
            flaga = true;
        }
    }
}
int main()
{
    char opcja[2];
    bool flaga = true;
    printf("Witaj uzytkowniku!\nPonizszy program pozwala na wprowadzenie i przechowywanie danych o ksiazkach, filmach oraz grach planszowych.\n");
    while(flaga)
    {
        printf("-----------------------------------\n");
        printf("Dostepne opcje programu:\n");
        printf("1. Dodaj nowy obiekt\n2. Usun obiekt\n3. Edytuj dane obiektu\n4. Zmien status obiektu\n5. Wyszukaj obiekt\n6. Wyswietl baze po nazwach obiektu\n7. Wyswietl obiekty wypozyczone\n8. Zapisz do pliku\n9. Odczytaj z pliku\n10. Zakoncz program\n");
        printf("-----------------------------------\n");
        printf("Wybierz opcje: ");
        scanf("%s", &opcja);
        int tmp;
        sscanf(opcja,"%d",&tmp);

        switch(tmp)
        {
            case 1:
                wielokrotne_dodawanie();
                break;
            case 2:
                usun_obiekt();
                break;
            case 3:
                edytuj_dane_obiektu();
                break;
            case 4:
                zmien_status_obiektu();
                break;
            case 5:
                wyszukaj_obiekt();
                break;
            case 6:
                wyswietl_baze_po_nazwach();
                break;
            case 7:
                wyswietl_obiekty_wypozyczone();
                break;
            case 8:
                zapisz_do_pliku();
                break;
            case 9:
                odczytaj_z_pliku();
                break;
            case 10:
                printf("Program zakonczyl dzialanie!\n");
                flaga = false;
                break;
            default:
                printf("Ten program nie zawiera opcji o takim numerze...\nProsze wybrac numer opcji sposrod liczb 1 - 10\n");
                flaga = true;
                break;
        }
    }
}
