using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace travelwhims.Models.Entities
{
    public class CustomerModel
    {

        public int id { get; set; }

        [Required]
        [StringLength(30, ErrorMessage = "Name should not exceed 30 characters")]
        [MinLength(6, ErrorMessage = "Name should be atleast 6 letters")]
        public string c_name { get; set; }
        [Required]
        [StringLength(10, ErrorMessage = "Username should not exceed 10 characters")]
        [MinLength(3, ErrorMessage = "Username should be atleast 3 letters")]
        public string c_username { get; set; }

        [Required]
        public string u_password { get; set; }

        [Required]
        [MinLength(11, ErrorMessage = "Phone number should be 11 number")]
        public int c_phone { get; set; }

        [Required]
        [StringLength(80, ErrorMessage = "Address should not exceed 80 characters")]
        public string c_address { get; set; }

        [DisplayName("Upload File")]
        public string c_dp { get; set; }

        [Required]
        public string c_mail { get; set; }

        public HttpPostedFileBase profilepicture { get; set; }

    }
}