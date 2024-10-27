import tkinter
root = tkinter.Tk()
root.geometry('500x500')
sc=tkinter.Scale(root, from_=1, to=100, length=700, orient=tkinter.HORIZONTAL, tickinterval=10)
sc.pack()
def display():
    tkinter.Label(root, text=sc.get()).pack
root.mainloop()
