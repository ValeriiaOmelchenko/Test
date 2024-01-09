import tkinter as tk
from tkinter import messagebox
import serial

ser = serial.Serial('COM3', 9600)  

def read_angle():
    ser.write(b'200')  
    angle = ser.readline().decode().strip()
    messagebox.showinfo("Read Angle", f"Current Angle: {angle} degrees")

def write_angle():
    new_angle = entry.get()
    if new_angle.isdigit() and 0 < int(new_angle) < 180:
        ser.write(f"w{new_angle}\n".encode()) 
        messagebox.showinfo("Write Angle", f"Angle set to {new_angle} degrees")
    else:
        messagebox.showerror("Error", "Please enter a valid angle (0-180)")

def save_angle():
    ser.write(b'300')  
    messagebox.showinfo("Save Angle", "Current Angle saved to memory")

def auto_mode():
    ser.write(b'400')  
    messagebox.showinfo("Auto Mode", "Auto Mode is on!")



root = tk.Tk()
root.title("Servo Control GUI")


label = tk.Label(root, text="Enter new angle:")
label.pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=10)

read_button = tk.Button(root, text="Read Angle", command=read_angle)
read_button.pack(pady=10)

write_button = tk.Button(root, text="Write Angle", command=write_angle)
write_button.pack(pady=10)

save_button = tk.Button(root, text="Save Angle", command=save_angle)
save_button.pack(pady=10)

auto_button = tk.Button(root, text="Auto Mode", command=auto_mode)
auto_button.pack(pady=10)

root.mainloop()
