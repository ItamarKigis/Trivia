using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Net.Sockets;

namespace client
{
    public partial class Menu : Page
    {
        NetworkStream sock;

        public Menu(NetworkStream clientStream)
        {
            sock = clientStream;
            InitializeComponent();
        }

        private void ButtonPopUpLogout_Click(object sender, RoutedEventArgs e)
        {
            MainWindow mainWindow = Application.Current.MainWindow as MainWindow;
            mainWindow.Visibility = Visibility.Visible;
            Window win = (Window)this.Parent;
            win.Close();
        }
        private void ButtonQuit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }
        private void ButtonOpenMenu_Click(object sender, RoutedEventArgs e)
        {
            ButtonOpenMenu.Visibility = Visibility.Collapsed;
            ButtonCloseMenu.Visibility = Visibility.Visible;
        }

        private void ButtonCloseMenu_Click(object sender, RoutedEventArgs e)
        {
            ButtonOpenMenu.Visibility = Visibility.Visible;
            ButtonCloseMenu.Visibility = Visibility.Collapsed;
        }

        private void CreateRoomClick(object sender, MouseButtonEventArgs e)
        {
            this.Control.Content = new CreateRoom(sock);
        }
        private void JoinRoomClick(object sender, MouseButtonEventArgs e)
        {
            this.Control.Content = new JoinRoom();
        }
        private void StatisticsClick(object sender, MouseButtonEventArgs e)
        {
            this.Control.Content = new Statistics(sock);
        }
        private void BestScoresClick(object sender, MouseButtonEventArgs e)
        {
            this.Control.Content = new BestScore();
        }
    }
}
