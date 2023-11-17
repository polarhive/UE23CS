import tkinter
root = tkinter.Tk()

def click():
    tkinter.Label(root, text="button clicked").place(x=150, y=100)

tkinter.Button(root, bg='#11111b', command=click, activebackground='red').place(x=20, y=25)
root.mainloop()
