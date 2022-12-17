//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace travelwhims.Models.TWdatabase
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel;
    using System.Linq;
    using System.Web;

    public partial class Package
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Package()
        {
            this.CustomerPackages = new HashSet<CustomerPackage>();
        }
    
        public int id { get; set; }

        [Required]
        [StringLength(60, ErrorMessage = "Title should not exceed 60 characters")]
        public string pac_title { get; set; }

        [Required]
        [StringLength(500, ErrorMessage = "Details should not exceed 500 characters")]
        public string pac_bio { get; set; }

        [StringLength(100, ErrorMessage = "Destination should not exceed 100 characters")]
        [Required]
        public string pac_destinations { get; set; }


        [Required]
        public int pac_price { get; set; }

        [Required]
        public System.DateTime pac_tourdate { get; set; }

        [Required]
        [StringLength(600, ErrorMessage = "Pre-requisite should not exceed 600 characters")]
        public string pac_prerequisite { get; set; }

        
        [DisplayName("Upload File")]
        public string pac_thumbnail { get; set; }

        [Required]
        public System.DateTime pac_returndate { get; set; }

        [Required]
        public string pac_class { get; set; }

        [Required]
        public string pac_category { get; set; }

        
        public int pac_ta_fk { get; set; }

      
        public string pac_status { get; set; }


        [Required]
        public int pac_maxmember { get; set; }

        public HttpPostedFileBase profilepicture { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<CustomerPackage> CustomerPackages { get; set; }
        public virtual TravelAgency TravelAgency { get; set; }
    }
}


//@Html.ValidationMessageFor(m => m.StudentName, "Please enter student name.", new { @class = "text-danger" })
//[RegularExpression(@"^\d{2}-\d{5}-\d{1}$", ErrorMessage = "Id must follow XX-XXXXX-X")] 