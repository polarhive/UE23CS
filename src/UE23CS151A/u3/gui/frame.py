import tkinter
root = tkinter.Tk()
root.geometry('500x500')
frame=tkinter.Frame(root, width=500, height=100, bg="green")
frame.pack(side=tkinter.TOP, pady=20)
btn=tkinter.Button(frame, text="Text")
root.mainloop()
