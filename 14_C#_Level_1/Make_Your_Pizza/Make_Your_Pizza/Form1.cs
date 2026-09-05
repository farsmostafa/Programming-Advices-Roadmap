using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Make_Your_Pizza
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        enum enToppingOptions
        {
            eExtraChees = 1,
            eOnion = 2,
            eMushrooms = 4, eOlives = 8,
            eTomatoes = 16, eGreenPeppers = 32
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked)
            {
                lblSize.Text = "Small";
                return;
            }

            if (rbMedium.Checked)
            {
                lblSize.Text = "Medium";
                return;
            }

            if (rbLarge.Checked)
            {
                lblSize.Text = "Large";
                return;
            }

        }

        void UpdateCrust()
        {
            UpdateTotalPrice();
            if (rbThinCrust.Checked)
            {
                lblCrustType.Text = "Think Crust";
                return;
            }

            if (rbThickCrust.Checked)
            {
                lblCrustType.Text = "Thick Crust";
                return;
            }


        }

        void UpdateWhereToEat()
        {
            UpdateTotalPrice();

            if (rbEatIn.Checked)
            {
                lblWhereToEat.Text = "Eat In.";
                return;
            }

            if (rbTakeOut.Checked)
            {
                lblWhereToEat.Text = "Take Out.";
                return;
            }

        }

        void UpdateToppings()
        {
            UpdateTotalPrice();

            List<string> selectedToppings = new List<string>();

            if (chkExtraChees.Checked) selectedToppings.Add("Extra Cheese");
            if (chkOnion.Checked) selectedToppings.Add("Onion");
            if (chkMushrooms.Checked) selectedToppings.Add("Mushrooms");
            if (chkOlives.Checked) selectedToppings.Add("Olives");
            if (chkTomatoes.Checked) selectedToppings.Add("Tomatoes");
            if (chkGreenPeppers.Checked) selectedToppings.Add("Green Peppers");

            string strTopping = string.Join(",\n", selectedToppings);

            lblToppings.Text = string.IsNullOrEmpty(strTopping) ? "No Toppings" : strTopping;
        }

        float GetSelectedSizePrice()
        {
            if (rbSmall.Checked)

                return Convert.ToSingle(rbSmall.Tag);

            else if (rbMedium.Checked)

                return Convert.ToSingle(rbMedium.Tag);

            else
                return Convert.ToSingle(rbLarge.Tag);

        }

        float CalculateToppingsPrice()
        {


            float ToppingsTotalPrice = 0;

            if (chkExtraChees.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(chkExtraChees.Tag);
            }


            if (chkOnion.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(chkOnion.Tag);
            }

            if (chkMushrooms.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(chkMushrooms.Tag);
            }

            if (chkOlives.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(chkOlives.Tag);
            }

            if (chkTomatoes.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(chkTomatoes.Tag);
            }

            if (chkGreenPeppers.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(chkGreenPeppers.Tag);
            }



            return ToppingsTotalPrice;



        }

        float GetSelectedCrutPrice()
        {
            if (rbThinCrust.Checked)
                return Convert.ToSingle(rbThinCrust.Tag);
            else
                return Convert.ToSingle(rbThickCrust.Tag);

        }


        float GetSelectedWhereToEatPrice()
        {
            if (rbEatIn.Checked)
            {
                return Convert.ToSingle(rbEatIn.Tag);
            }
            else
            {
                return Convert.ToSingle(rbTakeOut.Tag);
            }
        }
            float CalculateTotalPrice()
            {
                return GetSelectedSizePrice() + CalculateToppingsPrice() + GetSelectedWhereToEatPrice() + GetSelectedCrutPrice();
            }

            void UpdateTotalPrice()
            {

                lblTotalPrice.Text = "$" + CalculateTotalPrice().ToString();

            }

            void UpdateOrderSummary()
            {
                UpdateSize();
                UpdateToppings();
                UpdateCrust();
                UpdateWhereToEat();
                UpdateTotalPrice();

            }

            void ResetForm()
            {
                btnOrderPizza.Visible = true;
                gbSize.Enabled = true;
                gbCrustType.Enabled = true;
                gbWhereToEat.Enabled = true;
                gbToppings.Enabled = true;
                rbSmall.Checked = true;
                rbThinCrust.Checked = true;
                rbEatIn.Checked = true;
                chkExtraChees.Checked = false;
                chkOnion.Checked = false;
                chkMushrooms.Checked = false;
                chkOlives.Checked = false;
                chkTomatoes.Checked = false;
                chkGreenPeppers.Checked = false;
            }



        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm Pizza Order", "Comfirm", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                MessageBox.Show("Order Placed Successfully", "Success",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                btnOrderPizza.Visible = false;
                gbSize.Enabled = false;
                gbCrustType.Enabled = false;
                gbWhereToEat.Enabled = false;
                gbToppings.Enabled = false;
            }
        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();

        }

        private void rbMedium_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }
        private void rbThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }
        private void rbThinkCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }
        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }
        private void rbTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }









        private void chkExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }
        private void btnResetForm_Click(object sender, EventArgs e)
        {
            ResetForm();
        }


    }
}
