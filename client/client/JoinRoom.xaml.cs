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
using Newtonsoft.Json;
using System.Threading;
using System.IO;

namespace client
{
    /// <summary>
    /// Interaction logic for JoinRoom.xaml
    /// </summary>
    /// 
    public class Room
    {
        public string Title { get; set; }
        public int Completion { get; set; }
    }
    public partial class JoinRoom : UserControl
    {
        NetworkStream sock;
        dynamic json;
        public JoinRoom(NetworkStream clientStream)
        {
            sock = clientStream;
            InitializeComponent();

            Thread thr = new Thread(changeRooms);
            thr.Start();
        }
        private void OpenRoomData_Click(object sender, RoutedEventArgs e)
        {
            RoomData Room = new RoomData();
            Room.Show();
        }
        public void changeRooms()
        {
            while (true)
            {
                Thread.Sleep(3000);
                try
                {
                    StreamReader rd = new StreamReader("C:\\Users\\משתמש\\Documents\\trivia\\client\\client\\RoomData.txt");
                    for (int i = 0; i < RoomList.Items.Count; i++)
                    {
                        this.Dispatcher.Invoke(() => {
                            RoomList.Items.RemoveAt(i);
                        });
                    }
                    string line;
                    while ((line = rd.ReadLine()) != null)
                    {
                        this.Dispatcher.Invoke(() =>
                        {
                            Button newButton = new Button();
                            newButton.Content = line;

                            RoomList.Items.Add(newButton);
                        });
                    }
                    rd.Close();
                }
                catch { }
            } 
        } 
    }
}