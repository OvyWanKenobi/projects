using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace travelwhims.Models.Entities
{
    public class AgencyModel
    {

        public int id { get; set; }
        public string ta_name { get; set; }
        public string ta_username { get; set; }

        public string u_password { get; set; }
        public string ta_rating { get; set; }
        public string ta_bio { get; set; }
        public string ta_mail { get; set; }
        public int ta_phone { get; set; }
        public string ta_dp { get; set; }
        public string ta_officeaddress { get; set; }

        public HttpPostedFileBase tadisplaypicture { get; set; }

    }
}