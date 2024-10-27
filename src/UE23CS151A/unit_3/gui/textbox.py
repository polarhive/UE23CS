import tkinter
root = tkinter.Tk()

root.title("sample")
root.configure(bg="black")
root.geometry("400x300")

l1=tkinter.Label(root, text="Enter your name: ", font='Inter').pack(padx=10, pady=10)
g1=tkinter.Entry(root, font="Inter").pack()
b1=tkinter.Button(root, text="Submit", command="display").pack()

def disp():
    st=g1.get()
    l2.tkinter.Label()
root.mainloop()
