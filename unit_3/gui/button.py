#w=Button(parent, options)
# parent window, options to change

import tkinter
root = tkinter.Tk()

l1=tkinter.Label(root, text="below is a button: ", font="sans-serif")
b1=tkinter.Button(root, bg='#11111b')

# don't use pack and grid simultaneously
#l1.pack()

l1.grid(row=0, column=0)
b1.grid()
#b1.place(x=20, y=25)

# keep mainloop here!!
root.mainloop()
