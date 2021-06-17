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

namespace client
{
    /// <summary>
    /// Interaction logic for JoinRoom.xaml
    /// </summary>
    public partial class JoinRoom : UserControl
    {
        NetworkStream sock;
        public JoinRoom(NetworkStream clientStream)
        {
            sock = clientStream;
            InitializeComponent();
        }

        private void OpenRoomData_Click(object sender, RoutedEventArgs e)
        {
            RoomData Room = new RoomData();
            Room.Show();
        }
        public void getRooms()
        {
            byte[] msg = new byte[1024];
            msg[0] = BitConverter.GetBytes(102)[0];
            sock.Write(msg, 0, msg.Length);
            sock.Flush();

            msg = new byte[4096];
            int byteRead = sock.Read(msg, 0, 4096);
            string response = System.Text.Encoding.UTF8.GetString(msg);
        }
    }
}
