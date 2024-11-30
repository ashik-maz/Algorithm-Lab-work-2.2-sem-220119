import matplotlib.pyplot as plt
import time

def draw_tower(disks, rods):
    plt.clf()  # Clear the current figure
    num_disks = len(disks[0]) + len(disks[1]) + len(disks[2])
    rod_positions = [1, 2, 3]
    disk_colors = ['#ff9999', '#66b3ff', '#99ff99', '#ffcc99', '#c2c2f0', '#ffb3e6']

    for i, rod in enumerate(rods):
        plt.plot([rod, rod], [0, num_disks], color='black', linewidth=5)

        # Draw disks
        for j, disk in enumerate(disks[i]):
            width = disk * .3
            center = rod_positions[i]
            height = j + 1
            plt.gca().add_patch(
                plt.Rectangle((center - width / 2, height - 0.5), width, 0.5,
                              color=disk_colors[disk % len(disk_colors)])
            )

    plt.xlim(0, 4)
    plt.ylim(0, num_disks + 1)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.axis('off')
    plt.pause(0.5)


def tower_of_hanoi_graphical(num, source, help, destination, disks, rods):
    if num == 1:
        print(f'Move disk {num} {source} to {destination}')
        disk = disks[source].pop()
        disks[destination].append(disk)
        draw_tower(disks, rods)
        return

    tower_of_hanoi_graphical(num - 1, source, destination, help, disks, rods)
    print(f'Move disk {num} {source} to {destination}')
    disk = disks[source].pop()
    disks[destination].append(disk)
    draw_tower(disks, rods)
    tower_of_hanoi_graphical(num - 1, help, source, destination, disks, rods)


# Main execution
num = int(input('Enter number of disks: '))
disks = [list(range(num, 0, -1)), [], []]  # Initial state of the rods
rods = [1, 2, 3]  # Rod positions for plotting

plt.figure(figsize=(8, 6))
draw_tower(disks, rods)
tower_of_hanoi_graphical(num, 0, 1, 2, disks, rods)
plt.show()