import cv2
import numpy as np
import matplotlib.pyplot as plt
import requests


SERVER_URL = "http://127.0.0.1:5000/receive_delay"

# Load image
image_path = "final Design.jpg"  # Ensure the correct file path
image = cv2.imread(image_path)

if image is None:
    print("Error: Image not found!")
    exit()


hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)     # Convert to HSV


color_ranges = {
    "Pink": [(160, 50, 50), (180, 255, 255)],    # Define color ranges in HSV
    "Black": [(0, 0, 0), (180, 100, 80)]
}

# Machine parameters
roller_width = 60.1  # mm
distance_between_rollers = 105  # mm
fabric_speed = 50.2  # mm/sec

# Image dimensions
image_height, image_width, _ = image.shape

detected_colors = {}
delay_data = []

for idx, (color_name, (lower, upper)) in enumerate(color_ranges.items()):
    mask = cv2.inRange(hsv, np.array(lower), np.array(upper))

    # Expand mask to capture small areas
    kernel = np.ones((3, 3), np.uint8)
    mask = cv2.dilate(mask, kernel, iterations=2)

    # Find nonzero points
    coords = cv2.findNonZero(mask)

    if coords is None:  
        print(f"Warning: No pixels detected for {color_name}")  
        continue  # Skip if color not found

    # Get the topmost occurrence
    first_pixel = min(coords, key=lambda x: x[0][1])  # Min Y-value
    pixel_y = first_pixel[0][1]

    # Convert pixel position to mm
    mm_position = (pixel_y / image_height) * roller_width

    
    min_mm_position = min(
        (mm_pos for _, (_, mm_pos, _) in detected_colors.items()), 
        default=mm_position
    )

    # Compute start delay
    delay_time = max(((mm_position - min_mm_position) + (distance_between_rollers * idx)) / fabric_speed, 0)

    # Store detected color details
    detected_colors[color_name] = (pixel_y, mm_position, delay_time)

    # Draw marker and label with dynamic scaling
    circle_size = max(10, image_width // 50)  # Dynamic size
    text_scale = max(1.0, image_width / 1000.0)  # Dynamic text size

    cv2.circle(image, (first_pixel[0][0], pixel_y), circle_size, (0, 255, 0), -1)  # Green dot
    cv2.putText(image, f"{color_name}", (first_pixel[0][0] + 40, pixel_y - 40),
                cv2.FONT_HERSHEY_SIMPLEX, text_scale, (0, 0, 255), 2)

    # Append to delay data
    delay_data.append({"color": color_name, "delay": delay_time})

# Save output image
plt.figure(figsize=(12, 8))
plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
plt.title("Detected Colors with Positions")
plt.savefig("output.png")
plt.show() 
# Print detected positions
for data in delay_data:
    print(f"Color: {data['color']}, Delay: {data['delay']:.2f} sec")

# Send delay data to the server
try:
    response = requests.post(SERVER_URL, json={"delays": delay_data})  
    if response.status_code == 200:
        print("Delay data successfully sent to the server.")
    else:
        print(f" Failed to send data. Server response: {response.status_code} - {response.text}")
except Exception as e:
    print(f" Error sending data to server: {e}")
