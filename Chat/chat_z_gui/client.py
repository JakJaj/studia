import socket
import threading
import tkinter
import tkinter.scrolledtext
from tkinter import simpledialog

proto = socket.getprotobyname('tcp')
HOST = 'localhost'
PORT = 2222

class Client:

    def __init__(self,host,port):
        
        #otwieranie polaczenia
        self.sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM,proto=proto)
        self.sock.connect((host,port))

        #otwieranie okna do wybieranie nazwy uzytkownika
        msg = tkinter.Tk()
        msg.withdraw()
             
        self.nickname = simpledialog.askstring("Nazwa uzytkownika: ","Prosze wpisac nazwe uzytkownika",parent=msg)
        
        self.gui_done = False
        self.running = True

        gui_thread = threading.Thread(target=self.gui_loop)
        receive_thread = threading.Thread(target=self.receive)

        gui_thread.start()
        receive_thread.start()

    def gui_loop(self):
        '''Funkcja odpowiedzialna za GUI'''
        self.win = tkinter.Tk()
        self.win.title('Chat')
        
        #ustawianie okna
        self.win.configure(bg="dark slate gray")

        #wstawianie okna z wiadomosciami
        self.wyswietlanie = tkinter.scrolledtext.ScrolledText(self.win)
        self.wyswietlanie.pack(padx=20,pady=5,) 
        self.wyswietlanie.config(state='disabled',width=55)

        #wstawianie labela z tekstem 'Wiadomosc'
        self.label = tkinter.Label(self.win, text="Wiadomosc: ", fg="white",bg="dark slate gray")
        self.label.config(font=('Tekton Pro',12))
        self.label.pack(padx=20,pady=5)
        #wstawianie okna w ktorym wpisywana jest wiadomosc

        self.wpisywanie = tkinter.Text(self.win,height=3)
        self.wpisywanie.pack(padx=20,pady=5)
        self.wpisywanie.config(width=55)
        
        #wstawianie guzika do wysylania
        self.send_button = tkinter.Button(self.win,text="Wyslij",command=self.writeButton)
        self.send_button.config(font=("Tekton Pro", 12,'bold'),fg='dark slate gray',width=20)
        self.send_button.pack(pady=10)

        #wlaczanie wysylania przez uzycia klawisza enter
        self.win.bind('<Return>',self.write)
        self.gui_done = True
        
        self.win.protocol("WM_DELETE_WINDOW",self.stop)
        self.win.mainloop()
        
    def stop(self):
        '''Zakonczenie dzialania programu'''
        self.running = False
        self.win.destroy()
        self.sock.close()
        exit(0)

    def write(self,event):
        '''Funkcja wysylajaca wiadomosc przez nacisniecie klawisza enter'''
        message = f"{self.nickname}: {self.wpisywanie.get(1.0,'end')}"
        self.sock.send(message[:-1].encode('utf-8'))
        self.wpisywanie.delete('1.0','end')

    def writeButton(self):
        '''Funkcja wysylajaca wiadomosc przez nacisniecie przycisku'''
        message = f"{self.nickname}: {self.wpisywanie.get(1.0,'end')}"
        self.sock.send(message.encode('utf-8'))
        self.wpisywanie.delete('1.0','end')

    def receive(self):
        '''Funkcja nasluchujaca wiadomosci od serwera'''
        while self.running:
            try:
                message = self.sock.recv(1024).decode('utf-8')
                if message == "NICKNAME":
                    self.sock.send(self.nickname.encode('utf-8'))
                else:
                    if self.gui_done:
                        self.wyswietlanie.config(state='normal')
                        self.wyswietlanie.insert('end', message)
                        self.wyswietlanie.yview('end')
                        self.wyswietlanie.config(state='disable')
            except ConnectionAbortedError:
                break
            except:
                print("Error")
                self.sock.close()
                break
                
client = Client(HOST,PORT)