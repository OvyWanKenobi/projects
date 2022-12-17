<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Category;
use App\Models\Course;
class Instructor extends Model
{
    use HasFactory;
    public $timestamps = false;

    public function instructorcategory(){
        return $this->belongsTo(Category::class, 'ins_cat_fk');
    }

   
    public function coursesbyinstructor(){
        return $this->hasMany(Course::class, 'c_instructor_fk');
    }
    
}
