#!/bin/python3
from PIL import Image

def extract_gif_frames_to_png(gif_path, output_dir):
    gif = Image.open(gif_path)
    frame_number = 0

    while True:
        try:
            gif.seek(frame_number)
            frame = gif.copy()

            frame = frame.convert("P", palette=Image.ADAPTIVE, colors=16)

            original_width, original_height = frame.size

            new_width = 256
            new_height = original_height
            new_frame = Image.new("RGBA", (new_width, new_height), (0, 0, 0, 0))

            new_frame.paste(frame, (0, 0))

            new_frame = new_frame.convert("P", palette=Image.ADAPTIVE, colors=16)

            output_path = f"{output_dir}/frame_{frame_number:03d}.png"
            new_frame.save(output_path, format="PNG")
            
            print(f"Frame {frame_number} saved as {output_path}")
            frame_number += 1
            
        except EOFError:
            break

gif_path = "opanim.gif"
output_dir = "frames"
extract_gif_frames_to_png(gif_path, output_dir)
