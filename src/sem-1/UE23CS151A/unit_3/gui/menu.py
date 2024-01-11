import tkinter
root = tkinter.Tk()
root.geometry('500x500')
menu=tkinter.Menu(root)
file=tkinter.Menu(menu)
about=tkinter.Menu(menu)
root.config(menu=menu)

def New():
    print("New")
def Open():
    print("Open")
def Exit():
    print("Exit")
def Contact():
    print("Contact")

menu.add_cascade(label="File", menu=file)
file.add_command(label="New", command=New)
file.add_command(label="Open", command=Open)
file.add_command(label="Exit", command=Exit)
menu.add_cascade(label="About", menu=about)
root.mainloop()
