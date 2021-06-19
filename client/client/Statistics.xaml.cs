﻿using System;
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
    /// Interaction logic for UserControl1.xaml
    /// </summary>
    ///         
    public partial class Statistics : UserControl
    {
        private int games = 0;
        private int right_answers = 0;
        private int wrong_answers = 0;
        private double average_time = 0;
        NetworkStream sock;
        public string Games
        {
            get { return games.ToString(); }
        }
        public string RightAnswers
        {
            get { return right_answers.ToString(); }
        }
        public string WrongAnswers
        {
            get { return wrong_answers.ToString(); }
        }
        public string AverageTime
        {
            get { return average_time.ToString(); }
        }
        public Statistics(NetworkStream clientStream)
        {
            sock = clientStream;
            getStatistics();
            InitializeComponent();
            this.DataContext = this;
        }
        public void getStatistics()
        {
            byte[] msg = new byte[4096];
            msg[0] = BitConverter.GetBytes(105)[0];
            sock.Write(msg, 0, msg.Length);
            sock.Flush();

            msg = new byte[4096];
            int byteRead = sock.Read(msg, 0, 4096);
            string response = System.Text.Encoding.UTF8.GetString(msg);

            string temp = response.Substring(5);
            Dictionary<string, Object> ans = JsonConvert.DeserializeObject<Dictionary<string, Object>>(temp);

            KeyValuePair<string, Object> kv;
            object s = ans.ElementAt(0).Value;

            foreach(object stat in ans.Values)
            {
            }
            
            object a = s.ToString();
            Console.WriteLine("1");
        }
    }
}
