import qrcode

qrcode_img = qrcode.make("https://forms.gle/XWKPgSQxvVRnh9zY8")
qrcode_img.save("EncuestaAlmacenamiento.png")