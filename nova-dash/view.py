import sys
import numpy as np
from PyQt6.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QGridLayout, QToolBar
from PyQt6.QtGui import QPixmap, QFont, QIcon, QAction 
from PyQt6.QtCore import Qt
import pyqtgraph as pg
from pyqtgraph.Qt import QtCore

class RacingDashboard(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("PacDash 3")
        self.setGeometry(100, 100, 1800, 1000)

        self.main_widget = QWidget(self)
        self.setCentralWidget(self.main_widget)

        self.layout = QGridLayout(self.main_widget)
        self.main_widget.setLayout(self.layout)

        self.initUI()

    def initUI(self):
        self.setStyleSheet("background-color: #2B2B2B; color: white;")

        # Add a toolbar
        toolbar = QToolBar("Main Toolbar", self)
        self.addToolBar(toolbar)
        toolbar.setStyleSheet("background-color: #2B2B2B; color: white;")

        # Add actions to the toolbar
        general_action = QAction(QIcon(None), "Geral", self)
        RPM_action = QAction(QIcon(None), "RPM", self)
        speed_action = QAction(QIcon(None), "Velocidade", self)
        angle_action = QAction(QIcon(None), "Ângulo", self)
        lat_gforce_action = QAction(QIcon(None), "G-Lateral", self)
        long_gforce_action = QAction(QIcon(None), "G-Longitudinal", self)
        temp_action = QAction(QIcon(None), "Temperatura CVT", self)

        toolbar.addAction(general_action)
        toolbar.addAction(RPM_action)
        toolbar.addAction(speed_action)
        toolbar.addAction(angle_action)
        toolbar.addAction(lat_gforce_action)
        toolbar.addAction(long_gforce_action)
        toolbar.addAction(temp_action)


        toolbar_layout = QHBoxLayout()
        toolbar_widget = QWidget()
        toolbar_widget.setLayout(toolbar_layout)
        toolbar_layout.addWidget(toolbar)
        toolbar_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.layout.addWidget(toolbar_widget, 0, 0, 1, 4)

        
        # left_section = QVBoxLayout()

        # self.channel_data_label = QLabel("Channels", self)
        # self.channel_data_label.setFont(QFont('Arial', 14))
        # self.channel_data_label.setStyleSheet("color: white;")
        # left_section.addWidget(self.channel_data_label)
        
   
        # self.channel_data_placeholder = QLabel("Channel data here...", self)
        # self.channel_data_placeholder.setStyleSheet("color: #AAAAAA;")
        # left_section.addWidget(self.channel_data_placeholder)

        # self.lap_list_label = QLabel("Lap List", self)
        # self.lap_list_label.setFont(QFont('Arial', 14))
        # self.lap_list_label.setStyleSheet("color: white;")
        # left_section.addWidget(self.lap_list_label)
        

        # self.lap_list_placeholder = QLabel("Lap list here...", self)
        # self.lap_list_placeholder.setStyleSheet("color: #AAAAAA;")
        # left_section.addWidget(self.lap_list_placeholder)

        # self.layout.addLayout(left_section, 1, 0, 1, 1)

        central_layout = QVBoxLayout()
        self.dynamic_graphs_widget = pg.GraphicsLayoutWidget(show=True)
        self.dynamic_graphs_widget.setBackground('#2B2B2B')
        central_layout.addWidget(self.dynamic_graphs_widget)

        self.layout.addLayout(central_layout, 1, 1, 1, 2)
        self.plot_dynamic_graphs()

        # right_section = QVBoxLayout()

        # self.settings_label = QLabel("Settings", self)
        # self.settings_label.setFont(QFont('Arial', 14))
        # self.settings_label.setStyleSheet("color: white;")
        # right_section.addWidget(self.settings_label)


        # self.settings_placeholder = QLabel("Settings here...", self)
        # self.settings_placeholder.setStyleSheet("color: #AAAAAA;")
        # right_section.addWidget(self.settings_placeholder)

        # self.controls_label = QLabel("Controls", self)
        # self.controls_label.setFont(QFont('Arial', 14))
        # self.controls_label.setStyleSheet("color: white;")
        # right_section.addWidget(self.controls_label)


        # self.controls_placeholder = QLabel("Controls here...", self)
        # self.controls_placeholder.setStyleSheet("color: #AAAAAA;")
        # right_section.addWidget(self.controls_placeholder)

        # self.layout.addLayout(right_section, 1, 3, 1, 1)

        # # Bottom Layout for images and summary
        # bottom_layout = QHBoxLayout()

        # self.image_label_1 = QLabel(self)
        # self.image_label_1.setPixmap(QPixmap("/mnt/data/race_image_1.jpg").scaled(200, 150, aspectRatioMode=Qt.AspectRatioMode.KeepAspectRatio))
        # bottom_layout.addWidget(self.image_label_1)

        # self.image_label_2 = QLabel(self)
        # self.image_label_2.setPixmap(QPixmap("/mnt/data/race_image_2.jpg").scaled(200, 150, aspectRatioMode=Qt.AspectRatioMode.KeepAspectRatio))
        # bottom_layout.addWidget(self.image_label_2)

        # self.summary_label = QLabel("Lap Summary\nLap 1: Time - 75.2s\nLap 2: Time - 74.8s\nLap 3: Time - 74.9s", self)
        # self.summary_label.setFont(QFont('Arial', 14))
        # self.summary_label.setStyleSheet("color: white;")
        # bottom_layout.addWidget(self.summary_label)

        # self.layout.addLayout(bottom_layout, 2, 0, 1, 4)

    def plot_dynamic_graphs(self):
        # Example graphs for different metrics
        self.gforce_plot = self.dynamic_graphs_widget.addPlot(title="Força G (Longitudinal)")
        self.gforce_plot.setLabel('left', 'Força G (g)')
        self.gforce_plot.setLabel('bottom', 'Tempo (s)')
        self.gforce_plot.showGrid(x=True, y=True, alpha=0.3)
        self.gforce_curve = self.gforce_plot.plot(pen=pg.mkPen(color='#FF6347', width=2))

        self.dynamic_graphs_widget.nextRow()

        self.speed_plot = self.dynamic_graphs_widget.addPlot(title="Velocidade")
        self.speed_plot.setLabel('left', 'Velocidade (km/h)')
        self.speed_plot.setLabel('bottom', 'Tempo (s)')
        self.speed_plot.showGrid(x=True, y=True, alpha=0.3)
        self.speed_curve = self.speed_plot.plot(pen=pg.mkPen(color='#00BFFF', width=2))

        self.dynamic_graphs_widget.nextRow()

        self.braking_plot = self.dynamic_graphs_widget.addPlot(title="Temperatura")
        self.braking_plot.setLabel('left', 'Temp (°C)')
        self.braking_plot.setLabel('bottom', 'Tempo (s)')
        self.braking_plot.showGrid(x=True, y=True, alpha=0.3)
        self.braking_curve = self.braking_plot.plot(pen=pg.mkPen(color='#32CD32', width=2))

        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.update_dynamic_graphs)
        self.timer.start(1000)

    def update_dynamic_graphs(self):
        # Simulated dynamic data
        t = np.linspace(0, 10, 1000)
        gforce = np.sin(t) + np.random.normal(size=1000) * 0.1
        speed = np.abs(np.sin(t / 2)) * 30 + np.random.normal(size=1000) * 5
        braking = np.abs(25 * np.log(t * 19)) + np.random.normal(size=1000) * 0.2

        self.gforce_curve.setData(t, gforce)
        self.speed_curve.setData(t, speed)
        self.braking_curve.setData(t, braking)

def main():
    app = QApplication(sys.argv)
    window = RacingDashboard()
    window.show()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()
