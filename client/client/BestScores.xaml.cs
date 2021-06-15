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
namespace client
{
    /// <summary>
    /// Interaction logic for temp.xaml
    /// </summary>
    public partial class temp : UserControl
    {
        private int first = 150;
        private int second = 100;
        private int third = 50;
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
        public temp()
        {
            InitializeComponent();
            this.DataContext = this;
        }

        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            
        }
    }
}
