from PIL import Image

def invert_image_colors(input_path, output_path):
    # Open the image
    image = Image.open(input_path)

    # Invert the colors, including alpha channel
    inverted_data = [(255 - i[0], 255 - i[1], 255 - i[2], i[3]) for i in image.getdata()]
    inverted_image = Image.new('RGBA', image.size)
    inverted_image.putdata(inverted_data)

    # Save the result
    inverted_image.save(output_path)

    
for i in range(0, 26):
    temp = str(chr(ord('a') + i))
    print(f'Letter(name: "{temp}", imageDarkMode: Image("{temp}_labelled_dark_transparent"), imageLightMode: Image("{temp}_labelled")),')
    #input_image_path = f"/Users/jakubjajonek/Developer/VSCode/Studia/kolory/{str(chr(ord('a') + i))}_labelled.png"
    #output_image_path = f"/Users/jakubjajonek/Developer/VSCode/Studia/kolory/{str(chr(ord('a') + i))}_labelled_dark.png"
    #invert_image_colors(input_image_path, output_image_path)
# Example usage:
