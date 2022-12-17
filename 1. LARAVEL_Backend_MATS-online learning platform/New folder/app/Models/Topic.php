<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Course;


class Topic extends Model
{
    use HasFactory;
    public $timestamps = false;

    public function topicofcourse(){
        return $this->belongsTo(Course::class,'t_course_fk');
    }

    public function quizintopic(){
        return $this->hasMany(Quiz::class,'q_topic_fk');
    }

}
