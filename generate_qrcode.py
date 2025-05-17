import qrcode
from PIL import Image

# Data you want to encode
data = "https://youtube.com"

# Create QR Code
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_H,
    box_size=10,
    border=5,
)

qr.add_data(data)
qr.make(fit=True)

# Create an image
img = qr.make_image(fill="black", back_color="white")

# Save the image
img.save("my_qr_code.png")

print("QR code generated and saved as my_qr_code.png")
