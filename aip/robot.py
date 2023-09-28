class Robot:
    '''
    Klasa opisujaca funkcjonowanie robota
    
    Atr:
    nazwa(str) - nazwa robota
    start(krotka) - miejsce w ktorym robot rozpoczyna
    miejsce(lista) - miejsce w ktorym robot się znajduje
    moc(int) - ilosc energii którą robot może się poruszyć'''
    
    def __init__(self,nazwa,start=(0,0),miejsce=[0,0],moc=9):
        self.nazwa = nazwa
        self.start = start
        self.miejsce = miejsce
        self.moc = moc
    
    def __str__(self):
        return self.nazwa

    @property
    def nazwa(self):
        txt = f"nazwa: {self.__nazwa}\nmiejsce: {self.__miejsce}"
        return txt
    @property
    def start(self):
        return self.__start

    @property
    def miejsce(self):
        return self.__miejsce

    @property
    def moc(self):
        return self.__moc

    @nazwa.setter
    def nazwa(self,nowa_nazwa):
        assert isinstance(nowa_nazwa,str)
        if len(nowa_nazwa) > 0:
            self.__nazwa = nowa_nazwa
    
    @start.setter
    def start(self,nowy_start):
        assert isinstance(nowy_start,tuple)
        self.__start = nowy_start
    
    @miejsce.setter
    def miejsce(self,nowe_miejsce):
        assert isinstance(nowe_miejsce,list)
        self.__miejsce = nowe_miejsce
    
    @moc.setter
    def moc(self,nowa_moc):
        assert isinstance(nowa_moc,int)
        if nowa_moc < 0:
            print("Podano wartość mniejszą od 0")
            self.__moc = 0
        else:
            self.__moc = nowa_moc
    
    ##########FUNKCJE#############
    def czy_wystarczy_mocy(self,wydatek_mocy):
        if self.__moc > wydatek_mocy:
            self.__moc -= wydatek_mocy
            return True
        else:
            raise Exception("Nie wystarczajaco mocy")


    def down(self,ilosc_ruchow):
        '''Funkcja sluzaca do poruszania sie robota o podana ilosc w dol'''
        if self.czy_wystarczy_mocy(ilosc_ruchow):
                self.__miejsce[1] += ilosc_ruchow
                self.__miejsce = [self.__miejsce[0],self.__miejsce[1]%8]

            
    def up(self,ilosc_ruchow):
        '''Funkcja sluzaca do poruszania sie robota o podana ilosc w gore'''
        if self.czy_wystarczy_mocy(ilosc_ruchow):
                self.__miejsce[1] -= ilosc_ruchow
                self.__miejsce = [self.__miejsce[0],self.__miejsce[1]%8]

    def left(self,ilosc_ruchow):
        '''Funkcja sluzaca do poruszania sie robota o podana ilosc w lewo'''
        if self.czy_wystarczy_mocy(ilosc_ruchow):
            
                self.__miejsce[0] -= ilosc_ruchow
                self.__miejsce = [self.__miejsce[0]%8,self.__miejsce[1]]

    def right(self,ilosc_ruchow):
        '''Funkcja sluzaca do poruszania sie robota o podana ilosc w prawo'''
        if self.czy_wystarczy_mocy(ilosc_ruchow):
                self.__miejsce[0] += ilosc_ruchow
                self.__miejsce = [self.__miejsce[0]%8,self.__miejsce[1]]

    def rysuj(self):
        '''Funkcja sluzaca do rysowania umiejscowienia robota na mapie'''
        for i in range(8):
            for j in range(8):
                if self.__miejsce[0] == j and self.__miejsce[1] == i:
                    print("x",end=" ")
                else:
                    print(".",end=" ")
                    if j == 7:
                        print("\n")
                

robot = Robot("R2D2",(5,3),[5,3],9)

print(robot)
robot.rysuj()
robot.up(5)
print()
robot.rysuj()
robot.left(3)
robot.rysuj()