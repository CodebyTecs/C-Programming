import matplotlib.pyplot as plt

x = [500, 1000, 1500, 2000, 2500]
y1 = [1000, 2000, 8000, 38000, 40000]
y2 = [0, 1000, 4000, 20000, 21000]
y3 = [0, 1000, 2000, 12000, 12000]
y4 = [0, 0, 2000, 11000, 10000]
y5 = [0, 1000, 2000, 10000, 10000]
y6 = [0, 1000, 2000, 11000, 10000]
y7 = [0, 0, 2000, 11000, 10000]

plt.plot(x, y1, label='1', color='blue')
plt.plot(x, y2, label='2', color='red')
plt.plot(x, y3, label='4', color='yellow')
plt.plot(x, y4, label='8', color='green')
plt.plot(x, y5, label='16', color='purple')
plt.plot(x, y6, label='32', color='pink')
plt.plot(x, y7, label='64', color='orange')

plt.title('Matrix size vs threads', fontsize=15)
plt.xlabel('Matrix size', fontsize=12, color='black')
plt.ylabel('Time (ms)', fontsize=12, color='black')
plt.legend()
plt.grid(True)
plt.show()