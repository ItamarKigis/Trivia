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
using System.Linq;

namespace client
{
    /// <summary>
    /// Interaction logic for Page1.xaml
    /// </summary>
    /// 
    public partial class SignUp : Page
    {
        public class Account
        {
            public string username;
            public string password;
            public string email;
        }
        NetworkStream sock;
        public SignUp(NetworkStream clientStream)
        {
            sock = clientStream;
            InitializeComponent();
        }
        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
        private void SignUp1_Click(object sender, RoutedEventArgs e)
        {
            LoginToServer();
        }
        private void LoginToServer()
        {
            Account account = new Account();
            account.password = PasswordInput.Text;
            account.username = UsernameInput.Text;
            account.email = EmailInput.Text;
            string json = JsonConvert.SerializeObject(account, Formatting.Indented);

            byte[] msg = new byte[1024];
            byte CodeByte = BitConverter.GetBytes(210)[0];
            byte[] lenOfJson = BitConverter.GetBytes(json.Length);
            Array.Reverse(lenOfJson);
            msg = addByteToArray(lenOfJson, CodeByte);
            msg = Combine(msg, Encoding.ASCII.GetBytes(json));
            sock.Write(msg, 0, msg.Length);
            sock.Flush();

            msg = new byte[4096];
            int byteRead = sock.Read(msg, 0, 4096);

            string response = System.Text.Encoding.UTF8.GetString(msg);
            string status = response.Substring(15, 3);
            if (status == "210")
            {
                this.SignUpFrame.Navigate(new Menu(sock));
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

