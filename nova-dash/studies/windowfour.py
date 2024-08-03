from PyQt6.QtWidgets import QApplication, QWidget
from PyQt6.QtGui import QIcon
from PyQt6.QtCore import QDir
import sys
import os

class Window(QWidget):
    def __init__(self):
        super().__init__()

        self.setGeometry(200, 200, 700, 400)
        self.setWindowTitle("Python GUI Development")

        icon_path = 'images/mcl.png'
        if not os.path.isfile(icon_path):
            print(f"File not found: {icon_path}")
        else:
            self.setWindowIcon(QIcon(icon_path))

        #self.setFixedWidth(700)
        #self.setFixedHeight(400)

        self.setStyleSheet('background-color: orange')
        self.setWindowOpacity(0.9)




app = QApplication(sys.argv)

# Set the current directory to the script's directory
QDir.setCurrent(os.path.dirname(os.path.abspath(__file__)))

window = Window()
window.show()
sys.exit(app.exec())
