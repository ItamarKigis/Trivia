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
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Net.Sockets;
using Newtonsoft.Json;

namespace client
{
    /// <summary>
    /// Interaction logic for temp.xaml
    /// </summary>
    public partial class BestScore : UserControl
    {
        private int first = 150;
        private int second = 100;
        private int third = 50;
        NetworkStream sock;
        public string First
        {
            get { return first.ToString(); }
        }
        public string Second
        {
            get { return second.ToString(); }
        }
        public string Third
        {
            get { return third.ToString(); }
        }
        public BestScore(NetworkStream clientStream)
        {
            sock = clientStream;
            getBestScore();
            InitializeComponent();
            this.DataContext = this;
        }

        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            
        }
        public void getBestScore()
        {
            byte[] msg = new byte[4096];
            msg[0] = BitConverter.GetBytes(107)[0];
            sock.Write(msg, 0, msg.Length);
            sock.Flush();

            msg = new byte[4096];
            int byteRead = sock.Read(msg, 0, 4096);
            string response = System.Text.Encoding.UTF8.GetString(msg);

            string temp = response.Substring(5);

            dynamic json = JsonConvert.DeserializeObject(temp);
            try
            {
                first = (int)json["statistics"][0];
                second = (int)json["statistics"][1];
                third = (int)json["statistics"][2];
            }
            catch(ArgumentOutOfRangeException e)
            {

            }
        }
    }
}
