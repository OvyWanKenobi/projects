<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\student_course;
use App\Models\Course;
class Student extends Model
{
    use HasFactory;
   
    public $timestamps = false;

    public function coursesinstudent(){
        return $this->hasMany(student_course::class, 'st_id');
    }
}
