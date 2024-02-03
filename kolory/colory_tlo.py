import cv2
import numpy as np

def remove_black_background(input_image_path, output_image_path):
    # Read the image
    img = cv2.imread(input_image_path, cv2.IMREAD_UNCHANGED)

    # Define the color to be treated as the background (black)
    background_color = [0, 0, 0, 255]

    # Create a mask for the black background
    mask = np.all(img[:, :, :3] == background_color[:3], axis=-1)

    # Set the alpha channel to 0 for pixels with black background
    img[mask, 3] = 0

    # Save the result
    cv2.imwrite(output_image_path, img)
    
for i in range(0, 26):
    print(str(chr(ord('a') + i)))
    input_image_path = f"/Users/jakubjajonek/Developer/VSCode/Studia/kolory/{str(chr(ord('a') + i))}_labelled_dark.png"
    output_image_path = f"/Users/jakubjajonek/Developer/VSCode/Studia/kolory/{str(chr(ord('a') + i))}_labelled_dark_transparent.png"
    remove_black_background(input_image_path, output_image_path)