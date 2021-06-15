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
    /// Interaction logic for UserControl1.xaml
    /// </summary>
    ///         
    public partial class Statistics : UserControl
    {
        private int games = 0;
        private int right_answers = 0;
        private int wrong_answers = 0;
        private double average_time = 0;
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
        public Statistics()
        {
            InitializeComponent();
            this.DataContext = this;
        }
    }
}
