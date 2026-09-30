using System;
using System.Data;
using DataAccessLayer;


namespace BusinessLayer
{
    public class clsContact
    {

        public int ID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }
        public string Phone { get; set; }
        public string Address { get; set; }
        public DateTime DateOfBirth { get; set; }
        public int CountryID { get; set; }
        public string ImagePath { get; set; }
        public enum enMode { AddNew, Update }
        public enMode Mode;
        private clsContact(int iD, string firstName, string lastName, string email, string phone, string address, DateTime dateOfBirth, int countryID, string imagePath)
        {
            this.ID = iD;
            this.FirstName = firstName;
            this.LastName = lastName;
            this.Email = email;
            this.Phone = phone;
            this.Address = address;
            this.DateOfBirth = dateOfBirth;
            this.CountryID = countryID;
            this.ImagePath = imagePath;
            Mode = enMode.Update;
        }

        public clsContact()
        {
            this.ID = -1;
            this.FirstName = "";
            this.LastName = "";
            this.Email = "";
            this.Phone = "";
            this.Address = "";
            this.DateOfBirth = DateTime.Now;
            this.CountryID = -1;
            this.ImagePath = "";
            Mode = enMode.AddNew;
        }





        public static clsContact Find(int ID)
        {
            string FirstName = "", LastName = "", Email = "", Phone = "",
                Address = "", ImagePath = "";
            DateTime DateOfBirth = DateTime.Now;
            int CountryID = 1;

            if (clsContactsDataAccess.GetContactInfoByID(ID, ref FirstName, ref LastName,
                ref Email, ref Phone, ref Address, ref DateOfBirth, ref CountryID, ref ImagePath))
            {
                return new clsContact(ID, FirstName, LastName, Email, Phone, Address, DateOfBirth, CountryID, ImagePath);
            }
            else
                return null;

        }


        private bool _AddNewContact()
        {
            this.ID = clsContactsDataAccess.AddNewContact(this.FirstName, this.LastName, this.Email,
                this.Phone, this.Address, this.DateOfBirth, this.CountryID, this.ImagePath);

            return (this.ID != -1);

        }
        private bool _UpdateContact()
        {
            return clsContactsDataAccess.UpdateContact(this.ID, this.FirstName, this.LastName, this.Email,
                this.Phone, this.Address, this.DateOfBirth, this.CountryID, this.ImagePath);
        }

        public static bool DeleteContact(int ID)
        {
            return clsContactsDataAccess.DeleteContact(ID);
        }

        public static DataTable GetAllContacts()
        {
            return clsContactsDataAccess.GetAllContacts();
        }

        public static bool IsContactExist(int ID)
        {
            return clsContactsDataAccess.IsContactExist(ID);
        }

        public bool Save()
        {
            switch (Mode)
            {
                case enMode.AddNew:
                    if (_AddNewContact())
                    {
                        Mode = enMode.Update;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                case enMode.Update:
                    return _UpdateContact();
                default:
                    return false;
            }
        }

    }
}
