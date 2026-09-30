using System;
using System.Data;
using DataAccessLayer;


namespace BusinessLayer
{
    public class clsCountry
    {
        public int ID { get; set; }
        public string CountryName { get; set; }
        public string Code { get; set; }
        public string PhoneCode { get; set; }
        public enum enMode { AddNew, Update }
        public enMode Mode;
        private clsCountry(int iD, string countryName, string Code, string PhoneCode)
        {
            this.ID = iD;
            this.CountryName = countryName;
            this.Code = Code;
            this.PhoneCode = PhoneCode;
            Mode = enMode.Update;
        }

        public clsCountry()
        {
            this.ID = -1;
            this.CountryName = "";
            this.Code = "";
            this.PhoneCode = "";
            Mode = enMode.AddNew;
        }





        public static clsCountry Find(int ID)
        {
            string CountryName = "", Code = "", PhoneCode = "";

            if (clsCountriesDataAccess.GetCountryInfoByID(ID, ref CountryName, ref Code, ref PhoneCode))
            {
                return new clsCountry(ID, CountryName, Code, PhoneCode);
            }
            else
                return null;

        }

        public static clsCountry Find(string CountryName)
        {
            string Code = "", PhoneCode = "";
            int ID = -1;

            if (clsCountriesDataAccess.GetCountryInfoByName(ref ID, CountryName, ref Code, ref PhoneCode))
            {
                return new clsCountry(ID, CountryName, Code, PhoneCode);
            }
            else
                return null;

        }


        private bool _AddNewCountry()
        {
            this.ID = clsCountriesDataAccess.AddNewCountry(this.CountryName, this.Code, this.PhoneCode);

            return (this.ID != -1);

        }
        private bool _UpdateCountry()
        {
            return clsCountriesDataAccess.UpdateCountry(this.ID, this.CountryName, this.Code, this.PhoneCode);
        }

        public static bool DeleteCountry(int ID)
        {
            return clsCountriesDataAccess.DeleteCountry(ID);
        }

        public static DataTable GetAllCountries()
        {
            return clsCountriesDataAccess.GetAllCountries();
        }

        public static bool IsCountryExist(int ID)
        {
            return clsCountriesDataAccess.IsCountryExist(ID);
        }

        public static bool IsCountryExist(string CountryName)
        {
            return clsCountriesDataAccess.IsCountryExist(CountryName);
        }

        public bool Save()
        {
            switch (Mode)
            {
                case enMode.AddNew:
                    if (_AddNewCountry())
                    {
                        Mode = enMode.Update;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                case enMode.Update:
                    return _UpdateCountry();
                default:
                    return false;
            }
        }


    }
}
