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
using System.IO;
using System.Net.Sockets;
using Newtonsoft.Json;
using System.Threading;

namespace client
{
    public partial class Menu : Page
    {
        NetworkStream sock;
        bool IsJoined = true;

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
            IsJoined = false;
            this.Control.Content = new CreateRoom(sock);
        }
        private void JoinRoomClick(object sender, MouseButtonEventArgs e)
        {
            IsJoined = true;
            this.Control.Content = new JoinRoom(sock);

            Thread thr = new Thread(getRooms);
            thr.Start();
        }
        private void StatisticsClick(object sender, MouseButtonEventArgs e)
        {
            IsJoined = false;
            this.Control.Content = new Statistics(sock);
        }
        private void BestScoresClick(object sender, MouseButtonEventArgs e)
        {
            IsJoined = false;
            this.Control.Content = new BestScore(sock);
        }

        public void getRooms()
        {
            while (IsJoined)
            {
                try
                {
                    StreamWriter sw = new StreamWriter(@".\RoomData.txt");
                    byte[] msg = new byte[4096];
                    msg[0] = BitConverter.GetBytes(102)[0];
                    try
                    {
                        sock.Write(msg, 0, msg.Length);
                        sock.Flush();
                    }
                    catch { }

                    msg = new byte[4096];
                    if (sock.DataAvailable)
                    {
                        int byteRead = sock.Read(msg, 0, msg.Length);
                    }
                    string response = System.Text.Encoding.UTF8.GetString(msg);

                    string temp = response.Substring(5);

                    dynamic json = JsonConvert.DeserializeObject(temp);

                    for (int i = 0; (json != null) && (json["status"] == "102") && (i < json["rooms"].Count); i++)
                    {
                        /*sw.WriteLine("Name: " + json["rooms"][i]["name"] + ", Max Players: " +
                            json["rooms"][i]["maxPlayers"] + ", Number of questions" + json["rooms"][i]["numOfQuestions"] +
                            ", Time Per Question: " + json["rooms"][i]["timePerQuestion"]);
                        */
                        File.WriteAllText("C:\\Users\\משתמש\\Documents\\trivia\\client\\client\\RoomData.txt",
                            ("Name: " + json["rooms"][i]["name"] + ", Max Players: " +
                            json["rooms"][i]["maxPlayers"] + ", Number of questions" + json["rooms"][i]["numOfQuestions"] +
                            ", Time Per Question: " + json["rooms"][i]["timePerQuestion"]));
                    }
                    sw.Close();
                    Thread.Sleep(3000);
                }
                catch { }
            }
        }
    }
}
