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
    /// Interaction logic for Page2.xaml
    /// </summary>
    public partial class CreateRoom : UserControl
    {
        public class CreateRoomData
        {
            public string roomName;
            public int maxUsers;
            public int questionCount;
            public int answerTimeout;
        }
        NetworkStream sock;
        public CreateRoom(NetworkStream clientStream)
        {
            sock = clientStream;
            InitializeComponent();
        }
        private void Send_Click(object sender, RoutedEventArgs e)
        {
            CreateRoomData requestData = new CreateRoomData();
            requestData.roomName = Name.Text;
            requestData.maxUsers =  int.Parse(NumOfPlayers.Text);
            requestData.questionCount = int.Parse(NumOfQuestions.Text);
            requestData.answerTimeout = int.Parse(TimePerQuestion.Text);
            string json = JsonConvert.SerializeObject(requestData, Formatting.Indented);

            byte[] msg = new byte[4096];
            byte CodeByte = BitConverter.GetBytes(101)[0];
            byte[] lenOfJson = BitConverter.GetBytes(json.Length);
            Array.Reverse(lenOfJson);
            msg = addByteToArray(lenOfJson, CodeByte);
            msg = Combine(msg, Encoding.ASCII.GetBytes(json));
            try
            {
                sock.Write(msg, 0, msg.Length);
                sock.Flush();

                msg = new byte[4096];
                int byteRead = sock.Read(msg, 0, 4096);
            }
            catch { }

            string response = System.Text.Encoding.UTF8.GetString(msg);
            Console.WriteLine(response);
            string status = response.Substring(15, 3);
            if (status == "101")
            {
                MessageBox.Show(status);
            }
            else
            {
                MessageBox.Show("Could not open the room, Please try again.");
            }
        }
        public static byte[] Combine(byte[] first, byte[] second)
        {
            byte[] bytes = new byte[first.Length + second.Length];
            Buffer.BlockCopy(first, 0, bytes, 0, first.Length);
            Buffer.BlockCopy(second, 0, bytes, first.Length, second.Length);
            return bytes;
        }
        public static byte[] addByteToArray(byte[] bArray, byte newByte)
        {
            byte[] newArray = new byte[bArray.Length + 1];
            bArray.CopyTo(newArray, 1);
            newArray[0] = newByte;
            return newArray;
        }
    }
}
