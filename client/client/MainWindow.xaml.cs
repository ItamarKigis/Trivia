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
using System.Net;
using System.Net.Sockets;
using Newtonsoft.Json;
namespace client
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public class Account
    {
        public string username;
        public string password;
        public string email;
    }

    public partial class MainWindow : Window
    {
        NetworkStream clientStream;
        public MainWindow()
        {
            try
            {
                TcpClient client = new TcpClient();
                IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 8989);
                client.Connect(serverEndPoint);
                clientStream = client.GetStream();

                InitializeComponent();
                DataContext = this;
            }
            catch(Exception e)
            {

            }
        }

        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void SignUp_Click(object sender, RoutedEventArgs e)
        {
            this.Content = new Menu();        
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

    }
}