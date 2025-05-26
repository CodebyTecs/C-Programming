import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Circle, Ellipse, Polygon, Wedge

fig, ax = plt.subplots(figsize=(8, 10))

# Голова (круг |z - 5 - 8i| ≤ 3)
head = Circle((5, 8), 3, fill=True, color='#f5e5b3', ec='black', alpha=0.9)
ax.add_patch(head)

# Уши (треугольники)
left_ear = Polygon(np.array([[3.5, 10], [4.5, 9], [3, 8.5]]), fill=True, color='#f5e5b3', ec='black')
right_ear = Polygon(np.array([[6.5, 10], [5.5, 9], [7, 8.5]]), fill=True, color='#f5e5b3', ec='black')
ax.add_patch(left_ear)
ax.add_patch(right_ear)

# Тело (эллипс)
body = Ellipse((5, 4.5), 4, 6, fill=True, color='#d4a373', ec='black', alpha=0.9)
ax.add_patch(body)

# Глаза (|z - 4 - 8.5i| ≤ 0.7 и |z - 6 - 8.5i| ≤ 0.7)
left_eye = Circle((4, 8.5), 0.8, fill=True, color='white', ec='black')
right_eye = Circle((6, 8.5), 0.8, fill=True, color='white', ec='black')
ax.add_patch(left_eye)
ax.add_patch(right_eye)

# Зрачки
left_pupil = Circle((4.2, 8.5), 0.3, fill=True, color='black')
right_pupil = Circle((5.8, 8.5), 0.3, fill=True, color='black')
ax.add_patch(left_pupil)
ax.add_patch(right_pupil)

# Клюв (треугольник вниз)
beak = Polygon(np.array([[5, 8], [4.7, 7.5], [5.3, 7.5]]), fill=True, color='#ff9900', ec='black')
ax.add_patch(beak)

# Крылья (два эллипса |z - 3 - 5i| ≤ 1.5 и |z - 7 - 5i| ≤ 1.5)
left_wing = Ellipse((3, 5), 1.5, 3.5, angle=20, fill=True, color='#8b5a2b', alpha=0.7, ec='black')
right_wing = Ellipse((7, 5), 1.5, 3.5, angle=-20, fill=True, color='#8b5a2b', alpha=0.7, ec='black')
ax.add_patch(left_wing)
ax.add_patch(right_wing)

# Лапки (когтистые)
left_foot = Wedge((4.2, 2), 0.5, 0, 180, fill=True, color='black')
right_foot = Wedge((5.8, 2), 0.5, 0, 180, fill=True, color='black')
ax.add_patch(left_foot)
ax.add_patch(right_foot)

# Настройки координатной плоскости
ax.set_xlim(0, 10)
ax.set_ylim(0, 11)
ax.set_aspect('equal')
ax.grid(True, linestyle='--', alpha=0.5)
ax.set_xlabel('Re(z) (действительная ось)', fontsize=12)
ax.set_ylabel('Im(z) (мнимая ось)', fontsize=12)
ax.set_title('Сова на комплексной плоскости', pad=20, fontsize=14)

plt.tight_layout()
plt.show()