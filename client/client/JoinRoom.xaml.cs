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

namespace client
{
    /// <summary>
    /// Interaction logic for JoinRoom.xaml
    /// </summary>
    public partial class JoinRoom : UserControl
    {
        public JoinRoom()
        {
            InitializeComponent();
        }

        private void OpenRoomData_Click(object sender, RoutedEventArgs e)
        {
            RoomData Room = new RoomData();
            Room.Show();
        }
    }
}
