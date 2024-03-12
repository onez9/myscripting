



class Parrent
  def say(message)
    p message
    p "私に日本語が好きです"
  end
end

class Children < Parrent
  def say(message)
    super
  end
end

Children.new.say("Hello, Misha")