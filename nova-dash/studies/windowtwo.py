from PyQt6.QtWidgets import QApplication, QMainWindow
import sys

app = QApplication(sys.argv)

window = QMainWindow()
window.statusBar().showMessage("Mensagem cabulosa")
window.menuBar().addMenu("File")

window.show()

sys.exit(app.exec())